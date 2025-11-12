#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e4+15,N=1105;
int n,m,k,fa[M],num[N],ans,sum;
struct Node{
	int u,v,w;
}a[M*100],c[15][M];
vector<Node> b[N],d;
int find(int x)
{
	if(x==fa[x])
		return x;
	return fa[x]=find(fa[x]);
}
void uniset(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
		fa[x]=y;
}
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			uniset(a[i].u,a[i].v);
			ans+=a[i].w;
			b[0].push_back(a[i]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>num[1<<(i-1)];
		for(int j=1,x;j<=n;j++)
		{
			cin>>x;
			c[i][j]={j,n+i,x};
		}
		sort(c[i]+1,c[i]+n+1,cmp);
	}
	for(int i=1;i<(1<<k);i++)
	{
		int x=log2(i),y=(i^(1<<x)),now1=0,now2=1;
		sum=num[i]=num[1<<x]+num[y];
		x++;
		d.clear();
		for(int l,r;now1<b[y].size()||now2<=n;)
		{
			l=r=2e9;
			if(now1<b[y].size())
				l=b[y][now1].w;
			if(now2<=n)
				r=c[x][now2].w;
			if(l<=r)
				d.push_back(b[y][now1]),now1++;
			else
				d.push_back(c[x][now2]),now2++;
		}
		for(int j=1;j<=n+k;j++)
			fa[j]=j;
		for(int j=0;j<d.size();j++)
		{
			if(find(d[j].u)!=find(d[j].v))
			{
				uniset(d[j].u,d[j].v);
				sum+=d[j].w;
				b[i].push_back(d[j]);
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
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

Ren5Jie4Di4Ling5%
*/
