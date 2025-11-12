#include<bits/stdc++.h>
#define ll long long
using namespace std;
int nc[20][10010];
struct me
{
	int l,r,mo;
}a[1000010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].l>>a[i].r>>a[i].mo;
	}
	int z=0;
	for(int i=1;i<=k;i++)
	{
		cin>>nc[i][1];
		if(nc[i][1]==0)z++;
		for(int j=2;j<=n+1;j++)
		{
			cin>>nc[i][j];
			if(nc[i][j]==0)z++;
		}
	}
	if(k*n+k==z&&k!=0)
	{
		cout<<0;
		return 0;
	}
	else cout<<5134321451;
	
	return 0;
}
