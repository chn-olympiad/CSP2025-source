#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10000 , M = 1000000;
int n,m,k,ans,c[20],a[20][N+10];

struct edge
{
	int u,v,s;
}p[2*M+1000];

bool cmp(edge p1,edge p2)
{
	return p1.s < p2.s;
}

int fa[N+10];

int find(int x)
{
	if(fa[x] == x)
		return fa[x] = x;
	return fa[x] = find(fa[x]);
}

void add(int x,int y)
{
	int fx = find(x) , fy = find(y);
	fa[fy] = fx;
} 

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin>>n>>m>>k;
	
	for(int i=1,u,v,s;i<=m;i++)
	{
		cin>>u>>v>>s;
		p[i] = {u,v,s};
	}
	
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	
	int mx = 0; 
	sort(p+1,p+1+m,cmp);
		
	for(int i=1;i<=n;i++)
		fa[i] = i;
		
	for(int i=1;i<=m;i++)
	{
		int fx = find(p[i].u) , fy = find(p[i].v);
		if(fx == fy)
			continue;
		ans += p[i].s;
		add(fx,fy);
		mx = p[i].s;
	}
	
	ans = 0;
	
	for(int i=1,u,v,s;i<=k;i++)
	{
		int mn = 1e15;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j] + c[i] < mn)
			{
				u = j;
				mn = a[i][j] + c[i] ;
			}
		}
		if(mn < mx)
		{
			ans += mn; 
			for(int j=1;j<=n;j++)
			{
				v = j;
				s = a[i][j];
				p[++m] = {u,v,s};
			}
		}
	}
	
	sort(p+1,p+1+m,cmp);
		
	for(int i=1;i<=n;i++)
		fa[i] = i;
		
	for(int i=1;i<=m;i++)
	{
		int fx = find(p[i].u) , fy = find(p[i].v);
		if(fx == fy)
			continue;
		ans += p[i].s;
		add(fx,fy);
	}
	cout<<ans;
	
	return 0;
} 
