#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e4+5;
struct node{
	ll u,v,w,id;
};
ll n,m,k,ans;
ll w0[15],wt[N],f[N];
vector <node> cnt;
bool use[15];
bool cmp(node x,node y)
{
	return (x.w+(w0[x.id]/k))<(y.w+(w0[y.id]/k));
}
ll find(ll x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		cnt.push_back(node{u,v,w,0});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&w0[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&wt[j]);
		for(int j=1;j<=n;j++)
			for(int jj=j+1;jj<=n;jj++)
				cnt.push_back(node{j,jj,wt[j]+wt[jj],i});
	}
	sort(cnt.begin(),cnt.end(),cmp);
	for(unsigned int i=0;i<cnt.size();i++)
	{
		ll u=find(cnt[i].u);
		ll v=find(cnt[i].v);
		if(u!=v)
		{
			f[u]=v;
			use[cnt[i].id]=1;
			ans+=cnt[i].w;
			n--;
			if(n==1) break;
		}
	}
	for(int i=1;i<=k;i++)
		if(use[i]) ans+=w0[i];
	cout<<ans;
	return 0;
}
