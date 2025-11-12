#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],p;
bool vis[20][20];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=1,q=1;
	vis[1][1]=1;
	while(1)
	{
		if(a[q]==p)
		{
			cout<<x<<' '<<y;
			break;
		}
		q++;
		if(!vis[x][y-1]&&y-1>=1) vis[x][--y]=1;
		else if(!vis[x][y-1]&&y+1<=n) vis[x][++y]=1;
		else vis[x++][y]=1;
	}
	return 0;
}
