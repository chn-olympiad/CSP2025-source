#include<bits/stdc++.h>
using namespace std;
int a[109];
int s[19][19];
void dfs(int x,int y,int js){
	if(s[x][y]!=-1){
		return ;
	}
	s[x][y]=a[js];
	dfs(x+1,y,js-1);
	dfs(x-1,y,js-1);
	dfs(x,y+1,js-1);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=-1;
		}
	}
	dfs(1,1,n*m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r==s[i][j]){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
} 