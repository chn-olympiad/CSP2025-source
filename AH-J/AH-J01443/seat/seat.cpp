#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,nn,x=1,y=1,l,a[105],vis[15][15];
bool cmp(int n,int m){
	return n>m;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
	nn=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++)
	{
		vis[x][y]=a[i];
		if(!l)
			x++;
		else
			x--;
		if(x==n+1) x=n,y++,l=1;
		if(x==0) x=1,y++,l=0;
	}
	for(int i=1; i<=n; i++,cout<<"\n")
		for(int j=1; j<=m; j++)
			if(vis[i][j]==nn)
			{
				cout<<j<<" "<<i;
				return 0;
			}
    return 0;
}
