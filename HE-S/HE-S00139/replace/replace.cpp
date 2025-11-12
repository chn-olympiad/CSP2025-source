#include <bits/stdc++.h>
using namespace std;

int n, q;
int les[200010];
int whs[2][200010];
int let[200010];
int wht[2][200010];

char st[5000010];

int main(){
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++){
		scanf("%s", st+1);
		les[i]=strlen(st+1);
		for(int j=1; ; j++){
			if(st[j]=='b'){
				whs[0][i]=j;
				break;
			}
		}
		scanf("%s", st+1);
		for(int j=1; ; j++){
			if(st[j]=='b'){
				whs[1][i]=j;
				break;
			}
		}
	}
	for(int i=1; i<=q; i++){
		scanf("%s", st+1);
		let[i]=strlen(st+1);
		for(int j=1; ; j++){
			if(st[j]=='b'){
				wht[0][i]=j;
				break;
			}
		}
		scanf("%s", st+1);
		for(int j=1; ; j++){
			if(st[j]=='b'){
				wht[1][i]=j;
				break;
			}
		}
		int ans=0;
		for(int j=1; j<=n; j++){
			if(whs[1][j]-whs[0][j]==wht[1][i]-wht[0][i]){
				if(les[j]<=let[i]){
					if(wht[1][i]-(whs[1][j]-1)>=1 && wht[1][i]+(les[j]-whs[1][j])<=let[i]){
						if(wht[0][i]-(whs[0][j]-1)>=1 && wht[0][i]+(les[j]-whs[0][j])<=let[i]){
							ans++;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
	
}
