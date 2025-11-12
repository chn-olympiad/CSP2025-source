#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
using namespace std;
const int N=100005,M=1000005,K=15;
int n,m,k;
struct edge{
	int u,v;
	ll w;
}E[M],C[K][N],T[N];
int top;
ll cst[K];
struct Set{
	int fa[N],n;
	void init(int x)
	{
		n=x;
		for(int i=1;i<=n;i++) fa[i]=i;		
	}
	int find(int x){return x^fa[x]?fa[x]=find(fa[x]):x;}
	void merge(int u,int v){fa[find(u)]=find(v);}
}S;
ll res;
void init()
{
	S.init(n);
	for(int i=1;i<=m;i++)
	{
		int u=E[i].u,v=E[i].v;
		if(S.find(u)==S.find(v)) continue;
		S.merge(u,v);
		res+=E[i].w;C[0][++top]=E[i];
	}
}
void Merge(edge *A,edge *B,int &n,int m)
{
	int i=1,j=1,k=0;
	while(i<=n)
	{
		while(j<=m&&B[j].w<A[i].w) T[++k]=B[j++];
		T[++k]=A[i++];
	}
	while(j<=m) T[++k]=B[j++];
	n+=m;
	for(int i=1;i<=n;i++) A[i]=T[i];
}
void solve(int mask)
{
	ll sum=0;
	int L=0,c=n;
	Merge(E,C[0],L,n-1);
	for(int i=1;i<=k;i++)
	{
		if(!(mask&(1<<i-1))) continue;
		++c,sum+=cst[i];
		if(sum>=res) return;
		for(int j=1;j<=n;j++) 
			C[i][j].u=c;
		Merge(E,C[i],L,n);
	}
	S.init(c); 
	for(int i=1;i<=L;i++)
	{
		int u=E[i].u,v=E[i].v;
		if(S.find(u)==S.find(v)) continue;
		S.merge(u,v);
		sum+=E[i].w;
		if(sum>=res) return;
	}
	if(sum<res) res=sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;ll w;
		scanf("%d%d%lld",&u,&v,&w);
		E[i]=(edge){u,v,w};
	}
	sort(E+1,E+1+m,[&](edge a,edge b){return a.w<b.w;});
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&cst[i]);
		for(int j=1;j<=n;j++)
		{
			ll w;scanf("%lld",&w);
			C[i][j]=(edge){0,j,w};
		}
		sort(C[i]+1,C[i]+1+n,[&](edge a,edge b){return a.w<b.w;});
	}
	init();
	for(int mask=1;mask<(1<<k);mask++) 
		solve(mask);
	printf("%lld",res);
	return 0;
}
