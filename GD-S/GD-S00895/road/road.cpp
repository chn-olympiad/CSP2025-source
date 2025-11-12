#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node
{
	int u,v,w;
} ed[3000105];
int tot;
void addedge(int u, int v,int w)
{
	tot++;
	ed[tot].v=v;
	ed[tot].w=w;
	ed[tot].u=u;
	return;
}
int fa[10105];
int findf(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=findf(fa[x]);
	}
	return fa[x];
}
bool cmp(node p, node q)
{
	return p.w<q.w;
}
long long minn[10105];int n,m,k;
int c[10105];
bool check(int p, int q)
{
	if(q<=n)return 0;
//	cout<<" mmm"<<p<<" "<<q<<" "<<(1<<(q-n-1))<<" "<<!(p&(1<<(q-n-1)))<<endl;
	return !(p&(1ll<<(q-n-1)));
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int	i = 1; i <= m; i++ )
	{
		int u,v,w;
		cin>>u>>v>>w;
		addedge(u,v,w);
	}
	for(int i = 1; i <= k; i++ )
	{
		long long w;
		cin>>c[i];
		minn[i]=c[i];
//		addedge(0,i+n,c[i]);
//		addedge(i+n,0,c);
		for(int j = 1; j <= n; j++ )
		{
			cin>>w;
			minn[j]=min(minn[j],w);
			addedge(j,i+n,w);
//			addedge(i+n,j,w);
		}
	}
	sort(ed+1,ed+tot+1,cmp);
	long long sum=0,minn=99999999999;
	for(int ch= 0; ch < (1<<k);ch++ )
	{
		long long l=ch,now=1,cnt=n-1;
		while(l)
		{
			if(l&1)
			{
				sum+=c[now];
				cnt++;
			}
			l/=2;
			now++;
//			cout<<l<<" "<<sum<<endl;
		}
//		if(sum>minn)continue;
		for(int i= 1; i <= n+k;i++)fa[i]=i;
		for(int i= 1; i <= tot; i++ )
		{
			int u=ed[i].u,v=ed[i].v;
			if(check(ch,u)||check(ch,v))continue;
			int p=findf(u);
			int q=findf(v);
			if(p==q)
			{
				continue;
			}
			fa[p]=q;
			sum+=ed[i].w;
			cnt--;
			if(cnt==0)
			{
				break;
			}
			if(sum>minn)break;
		}
		minn=min(minn,sum);
		sum=0;
	}
		
	cout<<minn<<endl;
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
