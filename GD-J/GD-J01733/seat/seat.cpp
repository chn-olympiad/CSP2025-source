#include<bits/stdc++.h>
using namespace std;
int a[105];
int vis[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m);
	int y=1;
	int x=1;
	int d=1;
	for(int i=n*m-1;i>=0;i--){
		vis[y][x]=a[i];
		y+=d;
		if(y==n+1){
			d=-1;	
			y--;
			x++;
		} 
		if(y==0){
			d=1;
			y++;
			x++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j]==r){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	} 
	return 0;
}



