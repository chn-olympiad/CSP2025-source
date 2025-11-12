#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1e6+5;
typedef long long LL;
struct data{
	int u,v,w;
}A[M];
bool operator<(const data x,const data y){
	return x.w<y.w;
}
vector<data>E[11],F[10];
int n,m,k,c[N],fa[N];
LL ans=1LL<<60;
void init()
{
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
}
int find(int x)
{
	return fa[x]==x? x:fa[x]=find(fa[x]);
}
int mge(int u,int v)
{
	if(find(u)!=find(v))
	{
		fa[find(u)]=find(v);
		return 1;
	}
	return 0;
}
void dfs(int x,LL sum)
{
	if(sum>=ans)
		return;
	if(x==k)
	{
		for(data i:E[x])
			sum+=i.w;
		ans=min(ans,sum);
		return;
	}
	E[x+1]=E[x],dfs(x+1,sum);
	int s=0,t=0;
	init();
	E[x+1].clear();
	while(s<E[x].size()||t<F[x].size())
	{
		if(t==F[x].size()||s!=E[x].size()&&E[x][s]<F[x][t])
		{
			if(mge(E[x][s].u,E[x][s].v))
				E[x+1].push_back(E[x][s]);
			++s;
		}
		else
		{
			if(mge(F[x][t].u,F[x][t].v))
				E[x+1].push_back(F[x][t]);
			++t;
		}
	}
	dfs(x+1,sum+c[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&A[i].u,&A[i].v,&A[i].w);
	for(int i=0;i<k;i++)
	{
		scanf("%d",c+i);
		for(int j=1,x;j<=n;j++)
			scanf("%d",&x),F[i].push_back((data){n+i+1,j,x});
		sort(F[i].begin(),F[i].end());
	}
	sort(A+1,A+m+1);
	init();
	for(int i=1;i<=m;i++)
		if(mge(A[i].u,A[i].v))
			E[0].push_back(A[i]);
	dfs(0,0);
	printf("%lld\n",ans);
}
