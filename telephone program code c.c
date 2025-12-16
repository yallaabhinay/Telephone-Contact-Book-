#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

struct Contact contacts[100];
int count = 0;

// Function to add a contact
void addContact() {
    printf("Enter Name : ");
    scanf("%s", contacts[count].name);

    printf("Enter Phone Number : ");
    scanf("%s", contacts[count].phone);

    count++;
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts() {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// Function to search a contact by name
void searchContact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Contact Found!\nName: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

// Function to delete a contact
void deleteContact() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (int j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Telephone Contact Book ---\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}