#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,cnt=1,fa[20005],g[15],w[15];
ll ans=1e18;
struct s
{
	ll u,v,w;
}edge[2000006];
bool cmp(s x,s y)
{
	return x.w<y.w;
}
ll find(ll x)
{
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}
void merge(ll x,ll y)
{
	fa[find(x)]=find(y);
}
ll kruskal()
{
	ll sum=0;
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	sort(edge+1,edge+cnt+1,cmp);
	for(ll i=1;i<=cnt;i++)
	{
		ll x=edge[i].u,y=edge[i].v;
		//cout<<"edge:"<<x<<" to "<<y<<" "<<edge[i].w<<endl; 
		if((x>n&&!w[x-n])||(y>n&&!w[y-n]))continue;
		if(find(x)==find(y))continue;
		merge(x,y);
		sum+=edge[i].w;
		//cout<<"merge:"<<x<<" "<<y<<endl;
	}
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		edge[cnt].u=x,edge[cnt].v=y,edge[cnt].w=z;
		cnt++; 
	}
	for(ll i=1;i<=k;i++)
	{
		scanf("%lld",&g[i]);
		ll x;
		for(ll j=1;j<=n;j++)scanf("%lld",&x),edge[cnt].u=n+i,edge[cnt].v=j,edge[cnt].w=x,cnt++;
	}
	for(ll i=1;i<=(1<<k);i++)
	{
		ll q=1;
		while(w[q]>1)w[q]=0,w[q+1]++,q++;
		cout<<"w:";for(ll i=1;i<=k;i++)cout<<w[i];cout<<endl;
		ll sum=0;
		for(ll j=1;j<=k;j++)sum+=(w[j]==1)?g[j]:0;
		sum+=kruskal();
		ans=min(ans,sum);
		//cout<<sum<<endl;
		w[1]++;
	}
	printf("%lld",ans);
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
