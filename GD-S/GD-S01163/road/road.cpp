#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
const int MAXM=1e6+300,MAXN=1e4+100,MAXK=15;

int fa[MAXN];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void mer(int x,int y)
{
	fa[find(y)]=find(x);
}

struct edge
{
	int u,v;
	ll w;
}e[MAXM],e2[MAXM];
bool operator<(edge a,edge b)
{
	return a.w<b.w;
}
bool cho[MAXK];
ll c[MAXK],a[MAXK][MAXN];
ll ans;
int n,m,k;
edge tmp[MAXN];


void cldsu()
{
	for(int i=0;i<=n+10;i++)
		fa[i]=i;
}

void work()
{
	cldsu();
	ll ansn=0;
	int cnt=0,cnte=n-1,cntk=0;
	for(int i=1;i<=n-1;i++)
		e2[i]=tmp[i];
	cnte++;
	for(int i=1;i<=k;i++)
	{
		if(!cho[i]) continue;
		ansn+=c[i];
		cntk++;
		for(int j=1;j<=n;j++,cnte++)
			e2[cnte]=(edge){n+cntk,j,a[i][j]};
	}
	cnte--;
	sort(e2+1,e2+cnte+1);
	// if(cntk==0)
	// 	return;
	// for(int i=1;i<=k;i++)
	// 	cout<<cho[i];
	// for(int i=1;i<=cnte;i++)
	// 	cout<<"("<<e2[i].u<<","<<e2[i].v<<","<<e2[i].w<<")";
	// cout<<'\n';
	for(int i=1;i<=cnte;i++)
	{
		if(cnt>=n+cntk-1)
			break;
		if(find(e2[i].u)==find(e2[i].v)) continue;
		mer(e2[i].u,e2[i].v);
		cnt++;
		ansn+=e2[i].w;
	}
	// cout<<n+cntk-1<<'\n';
	ans=min(ans,ansn);
}
void dfs(int x)
{
	if(x>k)
	{
		work();
		return;
	}
	cho[x]=false;
	dfs(x+1);
	cho[x]=true;
	dfs(x+1);
}

int main()
{
	FILE* fp;
	fp=freopen("road.in","r",stdin);
	fp=freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cldsu();
	sort(e+1,e+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt>=n-1)
			break;
		if(find(e[i].u)==find(e[i].v)) continue;
		mer(e[i].u,e[i].v);
		cnt++;
		ans+=e[i].w;
		tmp[cnt]=e[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}