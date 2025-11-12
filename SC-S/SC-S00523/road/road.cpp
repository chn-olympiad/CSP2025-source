#include<bits/stdc++.h>
using namespace std;
struct road{
	int s,e,v;
}l[10001][10001];
int n,m,k,ll[10][10001],cs[10001]={0},q=0;
void dfs(int c)
{
	for(int i=1;i<=n;i++)
	{
		if(l[c][i].v>0)
		{
			cs[c]++;
			cs[i]++;
			l[c][i].v=l[i][c].v=-l[i][c].v;
			dfs(i);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int s,e,c;
		cin>>s>>e>>c;
		q+=c;
		l[s][e].v=c;
		l[s][e].s=s;
		l[s][e].e=e;
		l[e][s].v=c;
		l[e][s].s=e;
		l[e][s].e=s;
	}
	for(int i=0;i<k;i++)
	{
		int y=0;
		for(int t=0;t<=n;t++)
		{
			cin>>ll[i][t];
			if(ll[i][t]==0)y++;
		}
		if(y==n+1)
		{
			cout<<0;
			return 0;
		}
	}
	cout<<q;
	return 0;
}