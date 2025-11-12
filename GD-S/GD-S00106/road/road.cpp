#include <bits/stdc++.h>
using namespace std;
struct e{
	int u,v,w;
	bool operator < (const struct e &b) const{
		return w<b.w;
	}
}edge[1000007],te[17][10007],ae[100007],re[100007];
int c[17];
int f[10007];
int find(int x)
{
	if(f[x]==x) return x;
	f[x]=find(f[x]);
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>te[i][j].w,te[i][j].u=n+i,te[i][j].v=j;
	}
	sort(edge,edge+m);
	int cnt=0;
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int bit=0;bit<(1<<k);bit++)
	{
		cnt=0;
		int exs=0;
		for(int i=1;i<=n+k;i++) f[i]=i;
		long long at=0;
		for(int i=1;i<=k;i++)
		{
			if(bit&(1<<(i-1)))
			{
				exs++;
				at+=c[i];
				for(int j=1;j<=n;j++)
				{
					ae[cnt].w=te[i][j].w,ae[cnt].u=te[i][j].u,ae[cnt].v=te[i][j].v,cnt++;
				}
			}
		}
		sort(ae,ae+cnt);
		int p1=0,c=0;
		for(int i=0;i<m;i++)
		{
			while(p1<cnt&&ae[p1].w<edge[i].w)
			{
				if(find(ae[p1].u)!=find(ae[p1].v))
				{
					f[find(ae[p1].v)]=find(ae[p1].u);
					at+=ae[p1].w;
					c++;
				}
				if(c==exs+n-1) break;
				p1++;
			}
			if(c==exs+n-1) break;
			if(find(edge[i].u)!=find(edge[i].v))
			{
				f[find(edge[i].v)]=find(edge[i].u);
				at+=edge[i].w;
				c++;
			}
			if(c==exs+n-1) break;
		}
		ans=min(ans,at);
	}
	cout<<ans<<endl;
	return 0;
}
