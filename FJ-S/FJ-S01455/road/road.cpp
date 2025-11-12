#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e4+5,maxm=1e6+5;
int n,m,k; int tot=0; ll ans=0;
int f[maxn]; ll c[15]; bool vis[15];
struct Node {int u,v; ll w;}e[maxm];
inline bool cmp(Node x,Node y)
{return x.w<y.w;} 
inline int Find(int x)
{return x==f[x]?x:f[x]=Find(f[x]);} 
inline int read()
{
	int res=0; char x=getchar();
	while(!('0'<=x&&x<='9')) x=getchar();
	while('0'<=x&&x<='9')
	{res=res*10+x-'0'; x=getchar();}
	return res;
}
inline ll Read()
{
	ll res=0; char x=getchar();
	while(!('0'<=x&&x<='9')) x=getchar();
	while('0'<=x&&x<='9')
	{res=res*10+x-'0'; x=getchar();}
	return res;
}
inline ll Solve(int S)
{
	ll res=0; int All=0;
	for(int i=1;i<=k;i++)
	{
		if((S>>(i-1))&1)
		{
			All++;
			vis[i]=true;
			res+=c[i];
		}
		else vis[i]=false;
	}
//	cout<<res<<"\n";
	for(int i=1;i<=n+k;i++) f[i]=i;
	int sum=0;
	for(int i=1;i<=tot;i++)
	{
		if(e[i].u>n&&(!vis[e[i].u-n])) continue;
		if(e[i].v>n&&(!vis[e[i].v-n])) continue;
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u!=v)
		{
			sum++;
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<n<<"\n";
			f[u]=v; res+=e[i].w;
			if(sum==n+All-1) break;
			else if(res>ans) break;
		}
	}
//	cout<<res<<" :";
//	for(int i=1;i<=k;i++) cout<<vis[i]<<" ";
//	cout<<"\n";
	return res;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(); e[i].v=read();
		e[i].w=Read();
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u!=v)
		{
			e[++tot]=e[i];
			f[u]=v; ans+=e[i].w;
			if(tot==n-1) break;
		}
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=k;i++)
	{
		c[i]=Read();
		for(int u=1;u<=n;u++)
		{
			++tot;
			e[tot].u=u;
			e[tot].v=i+n;
			e[tot].w=Read();
//			cout<<i<<" "<<i+n<<" "<<e[tot].w<<" Readin\n";
		}
	}
	sort(e+1,e+tot+1,cmp);
//	for(int i=1;i<=tot;i++)
//	{
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
//	}
//	return 0;
	int mxs=(1<<k);
	for(int S=0;S<mxs;S++) ans=min(ans,Solve(S));
	cout<<ans<<"\n";
	return 0;
}
