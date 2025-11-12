#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],c;
int mp[101][101];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	memset(mp,-1,sizeof(mp));
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=1,w=0;
	mp[x][y]=a[1];
	while(a[++w]!=c) {
		if(mp[x+1][y]==-1&&x+1<=n) {
			x++;
			mp[x][y]=a[w];
		} else if(mp[x-1][y]==-1&&x-1>=1) {
			x--;
			mp[x][y]=a[w];
		} else if(mp[x][y+1]==-1&&y+1<=m) {
			y++;
			mp[x][y]=a[w];
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
