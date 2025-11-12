#include<bits/stdc++.h>
using namespace std;
int a[20][20],s[500];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	int num=s[1];
	sort(s+1,s+n*m+1);
	int x=n*m;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=s[x];
				x--;
			}
		}else{
			for(int j=n;j>=1;j--){
				a[i][j]=s[x];
				x--;
			}
		}
	}
	for(int i=1;i<=m;i++){
		int j;
		for(j=1;j<=n;j++){
			if(a[i][j]==num){
				printf("%d %d",i,j);
				break;
			}
		}
		if(a[i][j]==num) break;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
