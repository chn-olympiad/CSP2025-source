#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[15][15];
int s=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++)if(a[i]>a[1])s++;
	int x,y,i=1;
	x=y=1;
	b[1][1]=1;
	while(!(x==n&&y==m)&&i!=s){
		if(x+1<=n&&b[x+1][y]==0)b[++x][y]=1,i++;
		else if(x-1>=1&&b[x-1][y]==0)b[--x][y]=1,i++;
		else if(y+1<=m&&b[x][y+1]==0)b[x][++y]=1,i++;
	}
	cout<<y<<" "<<x;
	return 0;
} 
