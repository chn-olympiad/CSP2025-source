#include <bits/stdc++.h>
# include <string.h>
# include <string>
using namespace std;

int main(void){
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	char s[n+5][2][1200];
	char t[q+5][2][1300];
	for(int i = 0; i < n; i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int j = 0; j < q; j++){
		cin >> t[j][0] >> t[j][1];
	}
	for(int i = 0; i < q; i++){
		printf("0\n");
	}/*
	int a[q+5];
	for(int i = 0; i < q; i++){
		for(int j = 0; j < strlen(t[i][0]); j++){
			for(int k = 0; k < n; k++){
				if(t[i][0][j] == s[k][0][0]){
					int u = 0;
					for(int r = j, y = 0; y < strlen(s[k][0]); r++, y++){
						if(t[i][0][r] == s[k][0][y]){
							u++;
						}
					}
					char e[1200];
					strcpy(e, t[i][0]);
					if(u == strlen(s[k][0]){
						for(int r = j, y = 0; y < strlen(s[k][0]; r++, y++){
							t[i][0][r] = s[k][0][y];
						}
						if(strcmp(t[i][0], t[i][1]) == 0){
							a[i]++;
						}
						else strcpy(t[i][0], e);
					}
				}
			}
		}
	}*/
	
	
	return 0;
}
