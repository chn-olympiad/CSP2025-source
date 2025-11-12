#include<bits/stdc++.h>
#define int long long
#define pu push
#define em empty 
using namespace std;
struct bian{int u,v,w;}b[2000010];
bool operator <(bian a,bian b){return a.w>b.w;}
bool operator >(bian a,bian b){return a.w<b.w;}
int c[11],a[11][10010],s[10010];
priority_queue<bian>p;
int f(int a)
{
	if(s[a]==a)return a;
	s[a]=f(s[a]);
	return s[a];
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,d=0,ans=LONG_LONG_MAX;cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>b[i].u>>b[i].v>>b[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(m<=pow(10,5)&&k<=5)
		for(int i=0;i<pow(2,k);i++)
		{
			for(int j=1;j<=n+k;j++)s[j]=j;
			d=0;
			for(int j=1;j<=m;j++)p.pu(b[j]);
			for(int j=1;j<=k;j++)
				if((i&(1<<(j-1)))>0)
				{
					d+=c[j];
					for(int l=1;l<=n;l++)
					{
						b[0].u=n+j;b[0].v=l;b[0].w=a[j][l];
						p.pu(b[0]);
					}
				}
			while(!p.em())
			{
				if(f(p.top().u)==f(p.top().v)){p.pop();continue;}
				d+=p.top().w;
				s[f(p.top().v)]=f(p.top().u);
			}
			ans=min(ans,d);
		}
	else
	{
		for(int j=1;j<=n+k;j++)s[j]=j;
		for(int j=1;j<=m;j++)p.pu(b[j]);
		for(int j=1;j<=k;j++)
		{
			d+=c[j];
			for(int l=1;l<=n;l++)
			{
				b[0].u=n+j;b[0].v=l;b[0].w=a[j][l];
				p.pu(b[0]);
			}
		}
		while(!p.em())			
		{
			if(f(p.top().u)==f(p.top().v)){p.pop();continue;}
			d+=p.top().w;
			s[f(p.top().v)]=f(p.top().u);
		}
		ans=min(ans,d);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
