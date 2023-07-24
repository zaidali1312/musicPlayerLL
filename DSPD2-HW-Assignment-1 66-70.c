#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct Song {
	char song_name[100];
    char singer[100];
    char lyricist[100];
    char album[100];
    char composer[100];
    char genre[100];
    int duration;
    int flag;
    int index;
    struct Song* prev;
    struct Song* next;
}song;
struct Song *head = NULL;
struct Song *tail = NULL;
//song* InsertData();
//void printNode(struct Song* node);
//void InsertSong(struct Song **head);
//void removeDuplicates(song** head);
//void PrintPlaylist(struct Song **head);
//void DeleteSong(struct node **head_ref, char song_name[], char artist_name[]);
//void createPlaylist(struct Song* head);
//void displaySong(struct Song *head) 
//void displayRelativeSongDetails(struct Song* currentNode, int k, char* direction);
//void displaySongDetails(struct Song* head, int songNumber);
//void filter_playlist(struct Song* pl, char* attribute, char* value);
//void playInLoop(song* head);
//void shuffle_playlist(struct Song *head);
void sort_play(struct Song **head);


song* insertNode(song* myplay,char songName[],char singerName[],char lyricist[],char album[],char composer[],char genre[],int durMin){
	song *nptr=(song*)malloc(sizeof(song));
	strcpy(nptr->song_name,songName);
	strcpy(nptr->singer,singerName);
	strcpy(nptr->lyricist,lyricist);
	strcpy(nptr->album,album);
	strcpy(nptr->composer,composer);
	strcpy(nptr->genre,genre);
	nptr->duration=durMin;
    nptr->prev=nptr->next=NULL;
	if(myplay==NULL){
		myplay=nptr;
	}
	else{
		nptr->next = myplay;
        myplay->prev= nptr;
        myplay = nptr;
	}
	sort_play(&myplay);
    return myplay;
}


song* InsertData(){

    song *head;

    struct Song* new_node = (struct Song*)malloc(sizeof(struct Song));
    FILE* fp;
    char line[200];
    fp = fopen("dspd6670inputs.txt", "r");
    if (fp == NULL)  
    {
        printf("Error opening file.");
        exit(1);
    }

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        song *new_node = (song *)malloc(sizeof(song));
        sscanf(line, "%[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %[^;]; %d", new_node->song_name, new_node->singer, new_node->lyricist, new_node->album, new_node->composer, new_node->genre, &(new_node->duration));

        new_node->next = NULL;
        new_node->prev=NULL;
        if (head == NULL)
        {
            head = new_node;
        } 
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    fclose(fp);

    return head;


}


void InsertSong(struct Song** head) {
    
	struct Song* new_node = (struct Song*)malloc(sizeof(struct Song));

	printf("Enter song name: ");
    scanf("%s", new_node->song_name);
    printf("Enter singer name: ");
    scanf("%s", new_node->singer);
    printf("Enter lyricist name: ");
    scanf("%s", new_node->lyricist);
    printf("Enter album/film name: ");
    scanf("%s", new_node->album);
    printf("Enter composer name: ");
    scanf("%s", new_node->composer);
    printf("Enter genre: ");
    scanf("%s", new_node->genre);
    printf("Enter duration (in seconds): ");
    scanf("%d", &new_node->duration);

    new_node->next = NULL;
	new_node->flag=0;
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    struct Song* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

void printNode(struct Song* node) {
	printf("Song: %s\n", node->song_name);
	printf("Singer: %s\n", node->singer);
    printf("Lyricist: %s\n", node->lyricist);
    printf("Album/Film: %s\n", node->album);
    printf("Composer: %s\n", node->composer);
    printf("Genre: %s\n", node->genre);
    printf("Duration: %d seconds\n", node->duration);
}

void sort_play(struct Song **head){
    struct Song *current;
    song* index;
//    struct Song *temp = NULL;
//    while (current != NULL) {
//        temp = current->next;
//        while (temp != NULL) {
//            if (strcmp(current->song_name, temp->song_name) > 0) {
//                struct Song *prev = current->prev;
//                struct Song *next = temp->next;
//                if (prev != NULL) {
//                    prev->next = temp;
//                } else {
//                    *head = temp;
//                }
//                if (next != NULL) {
//                    next->prev = current;
//                }
//                current->next = next;
//                current->prev = temp;
//                temp->next = current;
//                temp->prev = prev;
//                current = temp;
//            }
//            temp = temp->next;
//        }
//        current = current->next;
//    }
    
    for(current = *head; current->next != NULL; current = current->next) {  
        //Index will point to node next to current  
        for(index = current->next; index != NULL; index = index->next) {  
            //If current's data is greater than index's data, swap the data of current and index  
            if(strcmp(current->song_name, index->song_name) > 0) {  
                char temp[20];
				strcpy(temp,current->song_name);  
                strcpy(current->song_name,index->song_name);  
                strcpy(index->song_name,temp);
				char a[20];
				strcpy(a,current->singer);  
                strcpy(current->singer,index->singer);  
                strcpy(index->singer,a);
				char b[20];
				strcpy(b,current->album);  
                strcpy(current->album,index->album);  
                strcpy(index->album,b);
				char c[20];
				strcpy(c,current->lyricist);  
                strcpy(current->lyricist,index->lyricist);  
                strcpy(index->lyricist,c);
				char d[20];
				strcpy(d,current->genre);  
                strcpy(current->genre,index->genre);  
                strcpy(index->genre,d);
				char e[20];
				strcpy(e,current->composer);  
                strcpy(current->composer,index->composer);  
                strcpy(index->composer,e);  
                int my=(int)current->duration;
                current->duration=index->duration;
                index->duration=my; 
            }  
        }  
    }  
    
    
}

void PrintPlaylist(struct Song **head) {
    
    sort_play(head);
    struct Song *printer=*head;
    struct Song *prev_temp=NULL;
    int c;
    printf("\n1.Accending\n2.Decending\n");
    scanf("%d",&c);
    if(c==1){
    	while(printer!=NULL){
	    	printNode(printer);
	    	printer=printer->next;
		}
	}
	else{
		prev_temp = *head;
		while(prev_temp->next!=NULL) prev_temp = prev_temp->next;
		while(prev_temp!=NULL){
			printNode(prev_temp);
			prev_temp=prev_temp->prev;
		}
	}
	
}
void displaySong(struct Song *head) {
    struct Song *current = head;
    int songCount = 0;

    // Count the number of songs in the playlist
    while (current != NULL) {
        songCount++;
        current->index=songCount;
        current = current->next;
    }

    // Display the playlist and index each song
    printf("Playlist:\n");
    current = head;
    while (current != NULL) {
        printf("%d. %s\n", current->index, current->song_name);
        current = current->next;
    }

    // Ask the user to select a song to play
    printf("Enter the serial number of the song you want to play: ");
    int songIndex;
    scanf("%d", &songIndex);

    // Find the song with the selected index
    current = head;
    while (current != NULL && current->index != songIndex) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid song index.\n");
        return;
    }

    // Display the selected song and the previous and next songs
    printf("Now playing: %s\n", current->song_name);

    if (current->prev!= NULL) {
        printf("Previous song: %s\n", current->prev->song_name);
    } else {
        printf("No previous song.\n");
    }

    if (current->next != NULL) {
        printf("Next song: %s\n", current->next->song_name);
    } else {
        printf("No next song.\n");
    }

    // Ask the user if they want to play the previous or next song
    printf("Enter 'p' to play the previous song, 'n' to play the next song, or any other key to exit: ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'p' && current->prev != NULL) {
        // Play the previous song
        printNode(current->prev);
    } else if (choice == 'n' && current->next != NULL) {
        // Play the next song
        printNode(current->next);
    }
}

// Function to display the details of a song given its serial number in the play-list
void displaySongDetails(struct Song* head, int songNumber) {
    struct Song* current = head;
    int count = 1;
    while (current != NULL && count < songNumber) {
        current = current->next;
        count++;
    }
    if (current != NULL) {
        printf("Song number %d:\n", songNumber);
        printNode(current);
    } else {
        printf("Song number %d not found.\n", songNumber);
    }
}

// Function to display the details of the kth previous or kth next song in the play-list from the current song
void displayRelativeSongDetails(struct Song* currentNode, int k, char* direction) {
    struct Song* current = currentNode;
    int count = 0;
    while (current != NULL && count < abs(k)) {
        if (strcmp(direction, "up") == 0) {
            current = current->prev;
        } else if (strcmp(direction, "down") == 0) {
            current = current->next;
        }
        count++;
    }
    if (current != NULL) {
        printf("Relative song details (k=%d, direction=%s):\n", k, direction);
        printNode(current);
    } else {
        printf("Relative song not found.\n");
    }
}

void filter_playlist(struct Song* pl, char* attribute, char* value) {
    struct Song* curr = pl;
    while (curr != NULL) {
        if (strcmp(attribute, "singer") == 0 && strcmp(curr->singer, value) == 0) {
            printNode(curr);
        } else if (strcmp(attribute, "album") == 0 && strcmp(curr->album, value) == 0) {
            printNode(curr);
        } else if (strcmp(attribute, "genre") == 0 && strcmp(curr->genre, value) == 0) {
            printNode(curr);
        }
        else if (strcmp(attribute, "lyricist") == 0 && strcmp(curr->lyricist, value) == 0) {
            printNode(curr);
        }
        else if (strcmp(attribute, "composer") == 0 && strcmp(curr->composer, value) == 0) {
            printNode(curr);
        }
        curr = curr->next;
    }
}
void DeleteSong(struct Song **head_ref, char song_name[], char artist_name[])
{
    // Initialize two pointers to traverse the doubly linked list
    struct Song *current = *head_ref;
    struct Song *temp = NULL;
 
    // Traverse through the list to find the song_name and artist_name provided by the user
    while (current != NULL) {
        // If the current node contains the song_name and artist_name, delete that node
        if (strcmp(current->song_name, song_name) == 0 && strcmp(current->singer, artist_name) == 0) {
            // Update the head of the linked list if the node to be deleted is the head node
            if (*head_ref == current) {
                *head_ref = current->next;
            }
            // If the node to be deleted is not the first node, update the pointers of the previous and next nodes
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            // Free the memory of the node to be deleted
            temp = current;
            current = current->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}
void createPlaylist(struct Song *head){
	
	struct Song input_att;
    strcpy(input_att.album,"#");
    strcpy(input_att.composer,"#");
    strcpy(input_att.genre,"#");
    strcpy(input_att.lyricist,"#");
    strcpy(input_att.singer,"#");
    strcpy(input_att.song_name,"#");
	int choice;
    do {
        printf("\nCreate a play-list based on the attribute\n"); //update
        printf("1. song_name\n");
        printf("2. singer\n");
        printf("3. lyricist\n");
        printf("4. album\n");
        printf("5. composer\n");
        printf("6. genre\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter song name: ");
                scanf("%s", input_att.song_name);
                break;
            case 2:
                printf("Enter singer name: ");
                scanf("%s", input_att.singer);
                break;
            case 3:
                printf("Enter lyricist name: ");
                scanf("%s", input_att.lyricist);
                break;
            case 4:
                printf("Enter album/film name: ");
                scanf("%s", input_att.album);
                break;
            case 5:
                printf("Enter composer name: ");
                scanf("%s", input_att.composer);
                break;
            case 6:
                printf("Enter genre: ");
                scanf("%s", input_att.genre);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);

    song* cur = head;
    song* lptr=NULL;
    while(cur!=NULL){
        if((strcmp(input_att.song_name,"#")==0 || strcmp(input_att.song_name,cur->song_name)==0) && 
            (strcmp(input_att.singer,"#")==0 || strcmp(input_att.singer,cur->singer)==0) &&
            (strcmp(input_att.lyricist,"#")==0 || strcmp(input_att.lyricist,cur->lyricist)==0) &&
            (strcmp(input_att.album,"#")==0 || strcmp(input_att.album,cur->album)==0) &&
            (strcmp(input_att.composer,"#")==0 || strcmp(input_att.composer,cur->composer)==0) &&
            (strcmp(input_att.genre,"#")==0 || strcmp(input_att.genre,cur->genre)==0)
            ){
                lptr = insertNode(lptr,cur->song_name,cur->singer,cur->lyricist,cur->album,cur->composer,cur->genre,cur->duration);
            }
            cur=cur->next;
    }
    PrintPlaylist(&lptr);

}
void removeDuplicates(song** myplay){
    // song* current=*myplay;
    // while (current != NULL) {
    //     temp = current->next;
    //     while (temp != NULL) {
    //         if (strcmp(current->song_name, temp->song_name) > 0) {
    //             struct Song *prev = current->prev;
    //             struct Song *next = temp->next;
    //             if (prev != NULL) {
    //                 prev->next = temp;
    //             } else {
    //                 **myplay = temp;
    //             }
    //             if (next != NULL) {
    //                 next->prev = current;
    //             }
    //             current->next = next;
    //             current->prev = temp;
    //             temp->next = current;
    //             temp->prev = prev;
    //             current = temp;
    //         }
    //         temp = temp->next;
    //     }
    //     current = current->next;
    // }
    sort_play(myplay);
	song* curr=*myplay;
	if(curr!=NULL){
		while(curr->next!=NULL){
			if(strcmp(curr->song_name,curr->next->song_name)==0){
				song* temp=curr->next->next;
				curr->next=temp;
				free(curr->next);
			}
			else{
				curr=curr->next;
			}
		}
	}
	
//    struct Node* current = *head_ref;
//    struct Node* next;
// 
//    /* traverse the list till the last node */
//    while (current->next != NULL) {
// 
//        /* Compare current node with next node */
//        if (current->data == current->next->data)
// 
//            /* delete the node pointed to by
//              'current->next' */
//            deleteNode(head_ref, current->next);
// 
//        /* else simply move to the next node */
//        else
//            current = current->next;

}
void playInLoop(song* head) {
    int k, i;
    song* current;
    printf("Enter the number of times you want to play the playlist in a loop: ");
    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        printf("Playing playlist for the %d time:\n", i);
        current = head;
        while (current != NULL) {
            printf("Song Name: %s\n", current->song_name);
            printf("Artist Name: %s\n", current->singer);
            printf("Lyricist Name: %s\n", current->lyricist);
            printf("Duration (in seconds): %d\n", current->duration);
            printf("\n");
            current = current->next;
        }
    }
}
void shuffle_playlist(struct Song *head) {
    int count = 0;
    struct Song input_att;
    strcpy(input_att.album,"#");
    strcpy(input_att.composer,"#");
    strcpy(input_att.genre,"#");
    strcpy(input_att.lyricist,"#");
    strcpy(input_att.singer,"#");
    strcpy(input_att.song_name,"#");
	int choice;
    do {
        printf("\nCreate a play-list based on the attribute\n"); //update
        printf("1. song_name\n");
        printf("2. singer\n");
        printf("3. lyricist\n");
        printf("4. album\n");
        printf("5. composer\n");
        printf("6. genre\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter song name: ");
                scanf("%s", input_att.song_name);
                break;
            case 2:
                printf("Enter singer name: ");
                scanf("%s", input_att.singer);
                break;
            case 3:
                printf("Enter lyricist name: ");
                scanf("%s", input_att.lyricist);
                break;
            case 4:
                printf("Enter album/film name: ");
                scanf("%s", input_att.album);
                break;
            case 5:
                printf("Enter composer name: ");
                scanf("%s", input_att.composer);
                break;
            case 6:
                printf("Enter genre: ");
                scanf("%s", input_att.genre);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
    song* cur = head;
    song array[100];
    while(cur!=NULL){
        if((strcmp(input_att.song_name,"#")==0 || strcmp(input_att.song_name,cur->song_name)==0) && 
            (strcmp(input_att.singer,"#")==0 || strcmp(input_att.singer,cur->singer)==0) &&
            (strcmp(input_att.lyricist,"#")==0 || strcmp(input_att.lyricist,cur->lyricist)==0) &&
            (strcmp(input_att.album,"#")==0 || strcmp(input_att.album,cur->album)==0) &&
            (strcmp(input_att.composer,"#")==0 || strcmp(input_att.composer,cur->composer)==0) &&
            (strcmp(input_att.genre,"#")==0 || strcmp(input_att.genre,cur->genre)==0)
            ){
            	cur->flag=0;
                strcpy(array[count].song_name,cur->song_name);
                strcpy(array[count].singer,cur->singer);
                strcpy(array[count].album,cur->album);
                strcpy(array[count].lyricist,cur->lyricist);
                strcpy(array[count].genre,cur->genre);
                strcpy(array[count].composer,cur->composer);
                array[count].duration=cur->duration;
                count=count+1;
            }
            cur=cur->next;
    }
    int mycount=0;
    while(mycount!=count){
		int random_number = rand() % count;
		if(array[random_number].flag==0){
			printNode(&array[random_number]);
			array[random_number].flag=1;
			mycount++;
		}
	}
	
}


//main


int main(){
    int choice,k,m,l,i;
    char att[20];
    char val[20];
    head=InsertData();
    do {
        printf("\nWelcome to Music Database\n");
        printf("1. Insert a new song\n");
        printf("2. Remove duplicates\n");
        printf("3. Print playlist\n");
        printf("4. Delete a song\n");
        printf("5. Create a new playlist\n");
        printf("6. Display current song and playlist\n");
        printf("7. Display kth song from current song in playlist\n");
        printf("8. Song by serial number:\n");
        printf("9. Filter playlist\n");
        printf("10. Play in loop\n");
        printf("11. Shuffle songs\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                InsertSong(&head);
                break;
            case 2:
                removeDuplicates(&head);
                break;
            case 3:
                PrintPlaylist(&head);
                break;
            case 4:
                printf("enter song name and singer name:\n");
                char a[100];
                char b[100];
                scanf("%s %s",a,b);
                DeleteSong(&head,a,b);
                break;
            case 5:
                createPlaylist(head);
                break;
            case 6:
                displaySong(head);
                break;
            case 7:
                
                printf("enter a number:\n");
                scanf("%d",&k);
                char dir[100];
                printf("enter direction (up or down):\n");
                scanf("%s",dir);
                displayRelativeSongDetails(head,k,dir);
                break;
            case 8:
                printf("enter a number:\n");
                scanf("%d",&m);
                displaySongDetails(head,m);
                break;
            case 9:
                scanf("%s", att);
                scanf("%s", val);
                filter_playlist(head,att,val);
                break;
            case 10:
                playInLoop(head);
                break;
            case 11:
                shuffle_playlist(head);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 0);
    return 0;
}



