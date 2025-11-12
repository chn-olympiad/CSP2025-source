#include <bits/stdc++.h>
using namespace std;
int s[110];
int classroom[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i]);
	}
	int u=s[1];
	sort(s+1,s+n*m+1);
	int x=1;
	int y=1;
	classroom[x][y]=s[n*m];
	int a=n*m-1;
	bool flag=false;
	while(a>0){
		if(x>=1&&x<n&&flag==false){
			x++;
		}
		else if(x==n&&flag==false){
			y++;
			flag=true;
		}
		else if(x==1&&flag==true){
			y++;
			flag=false;
		}
		else if(flag==true){
			x--;
		}
		classroom[x][y]=s[a];
		a--; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(classroom[i][j]==u){
				printf("%d %d",j,i);
			}
		}
	}
	return 0;
}