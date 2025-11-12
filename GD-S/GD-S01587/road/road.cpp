#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=2e6+5;
struct edge{
	int to,w,nxt;
}e[M];
int cnt,head[N];
void add(int u,int v,int coast)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].w=coast;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
struct city{
	int cc,a[N];
}c[15];
int n,m,k,ans=1e18;

bool iscity(int x,int cty){x--;return (1<<x)&cty;}
int take(int cty)
{
	int anss=0;
	for(int i=1;i<=k;i++)
	if(iscity(i,cty)) anss+=c[i].cc;
	return anss;
}

bool flag[N];
queue<int> q;
int solve1(int cty)
{
	memset(flag,0,sizeof(flag));
	int anss=1e18+7;
	while(!q.empty()) q.pop();
	q.push(1);flag[1]=1;
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		
	}
	return anss;
}

struct edgep{
	int to,w,from;
}ep[M];
int cntp;
void add2(int u,int v,int coast)
{
	cntp++;
	ep[cntp].from=u;
	ep[cntp].to=v;
	ep[cntp].w=coast;
}
bool cmp(edgep x,edgep y)
{
	return x.w<y.w;
}
int solve2(int cty)
{
	memset(flag,0,sizeof(flag));
	int anss=0,nn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=e[j].nxt)
		{
			int v=e[j].to,coast=e[j].w;
			if(iscity(i,cty)) coast=min(coast,c[i].a[v]);
			if(iscity(v,cty)) coast=min(coast,c[v].a[i]);
			add2(i,v,coast);
		}
	}
	for(int i=1;i<=k;i++)
	{
		if(!iscity(i,cty)) continue;
		for(int j=1;j<=n;j++)
		{
			add2(i+n,j,c[i].a[j]);
			add2(j,i+n,c[i].a[j]);
		}
	}
	sort(ep+1,ep+cntp+1,cmp);
	for(int i=1;i<=cntp;i++)
	{
		if(flag[ep[i].from]&&flag[ep[i].to]) continue;
		if(ep[i].from>n&&ep[i].to>n) continue;
		anss+=ep[i].w;
		flag[ep[i].from]=1;
		flag[ep[i].to]=1;
	}
	return anss+take(cty);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,coast;
		cin>>u>>v>>coast;
		add(u,v,coast);
		add(v,u,coast);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i].cc;
		for(int j=1;j<=n;j++)
		{
			cin>>c[i].a[j];
		}
			
	}
	for(int i=0;i<(1<<k);i++)
	{
		ans=min(ans,solve2(i));
	}
	cout<<ans;
	return 0;
}
