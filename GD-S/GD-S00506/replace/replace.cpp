#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, m;
char *ReplaceRule[214514][2], str[5145141], Tgt[5145141];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int i, cnt;
	for(i = 1; i <= n; i += 1) {
		scanf("%s", str);
		ReplaceRule[i][0] = (char*)calloc(strlen(str) + 5, sizeof(char));
		strcpy(ReplaceRule[i][0], str);
		scanf("%s", str);
		ReplaceRule[i][1] = (char*)calloc(strlen(str) + 5, sizeof(char));
		strcpy(ReplaceRule[i][1], str);
	}
	for(i = 1; i <= m; i += 1) {
		cnt = 0;
		scanf("%s %s", str, Tgt);
		if(strlen(str) != strlen(Tgt)) {
			printf("0");
			continue;
		}
		int j, needToReplace = 0;
		for(j = 0; j < strlen(str); j += 1) {
			if(str[j] != Tgt[j]) needToReplace += 1;
		}
		for(j = 1; j <= n; j += 1) {
			if(strlen(ReplaceRule[j][0]) < needToReplace) continue;
			char* Position = strstr(str, ReplaceRule[j][0]);
			if(Position != NULL) {
				char *newString = (char*)calloc(strlen(str) + 5, sizeof(char));
				strcpy(newString, str);
				Position = newString + (Position - str);
				memcpy(Position, ReplaceRule[j][1], strlen(ReplaceRule[j][1]));
				if(strcmp(newString, Tgt) == 0) {
					cnt += 1;
				}
				free(newString);
			}
		}
		printf("%d\n", cnt);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
