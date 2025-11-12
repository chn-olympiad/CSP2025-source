#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[150],vis[11][11];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,p;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	p=a[1];
	sort(a+1,a+1+m*n,cmp);
	int mp;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==p)
		{
			mp=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==0) vis[1][i]=(n*2)*(i/2);
		else vis[1][i]=(n*2)*(i/2)+1;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(i%2==1) vis[j][i]=vis[j-1][i]+1;
			else vis[j][i]=vis[j-1][i]-1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]==mp) cout<<j<<" "<<i;
		}
	}
	return 0;
}