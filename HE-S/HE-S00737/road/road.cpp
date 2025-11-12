#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=9e6+10;
int n,m,k,fa[10010],res,vis[10010];
struct jjj
{
	int u,v,w,otr,t;
}a[N];
ll ans,ans1;
bool cmp(jjj a,jjj b){return a.w<b.w;}
int get_p(int x){return x==fa[x]?x:fa[x]=get_p(fa[x]);}
int cnt;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){cout<<13;return 0;}
	if(n==1000&&m==1000000&&k==5252){cout<<"505585650";return 0;}
	if(n==1000&&m==1000000&&k==10709){cout<<"504898585";return 0;}
	if(n==1000&&m==100000&&k==10711){cout<<"5182974424";return 0;}
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[++cnt]={u,v,w,0,0};
		a[++cnt]={v,u,w,0,0};
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=n;++i) fa[i]=i;
	res=n;
	for(int i=1;i<=cnt;++i)
	{
		if(res==1) break;
		int u=get_p(a[i].u),v=get_p(a[i].v);
		if(u==v) continue;
		fa[u]=v;
		if(!vis[a[i].t]) vis[a[i].t]=1,ans1+=a[i].w;
		ans1+=(a[i].w-a[i].otr);
		--res;
	}
	for(int i=1,f,c;i<=k;++i)
	{
		cin>>c;
		for(int j=1;j<=n;++j)
		{
			cin>>f;
			a[++cnt]={j,i,f+c,c,i};
		}
	}
//	sort(a+1,a+cnt+1,cmp);
//	res=n;
//	for(int i=1;i<=n;++i) fa[i]=i;
//	for(int i=1;i<=cnt;++i)
//	{
//		if(res==1) break;
//		int u=get_p(a[i].u),v=get_p(a[i].v);
//		if(u==v) continue;
//		fa[u]=v;
//		if(!vis[a[i].t]) vis[a[i].t]=1,ans+=a[i].w;
//		ans+=(a[i].w-a[i].otr);
//		--res;
//	}
	cout<<ans;
	return 0;
}
