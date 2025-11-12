#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int ans;
int x[5005];
bool vis[5005];
void dfs(int be,int id,int maxx,int s,int nn)
{
	if(id==nn)
	{
		if(s>2*maxx)
			ans++;
		return ;
	}
	for(int j=be;j<=n;j++)
		dfs(j+1,id+1,max(maxx,x[j]),s+x[j],nn);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	if(n<=3)
	{
		if(x[1]+x[2]>x[3] && x[1]+x[3]>x[2] && x[2]+x[3]>x[1])
			cout<<1;
		else
			cout<<0;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			dfs(1,0,-0x3f3f3f3f,0,i);
		}
		cout<<ans;
	}
	
	return 0;
}
/*
Luogu id=1383031
*/
