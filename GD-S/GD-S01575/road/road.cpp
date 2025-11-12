#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll b[MAXN],c[MAXN],d[15][MAXN],fa[MAXN];
struct node
{
	ll q,w,e;
}a[MAXN];
bool cmp(node x,node y)
{
	return x.e<y.e;
}
ll findfa(ll x)
{
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}
vector<node>e;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,m,k,ans=0,cnt=0;
	cin>>n>>m>>k;
	for(register int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(register int i=1;i<=m;i++)
	{
		cin>>a[i].q>>a[i].w>>a[i].e;
	}
	sort(a+1,a+1+m,cmp);
	for(register int i=1;i<=m;i++)
	{
		ll q=findfa(a[i].q);
		ll w=findfa(a[i].w);
		if(q!=w)
		{
			ans+=a[i].e;
			fa[q]=w;
			b[++cnt]=i;
		}
	}
	for(register int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(register int j=1;j<=n;j++)
		{
			cin>>d[i][j];
		}
	}
	for(register int i=1;i<(1<<k);i++)
	{
		ll answer=0,t=0;
		vector<node>().swap(e);
		for(register int j=1;j<=cnt;j++)
		{
			e.push_back(a[b[j]]);
		}
		for(register int j=1;j<=n+10;j++)
		{
			fa[j]=j;
		}
		for(register int j=1;j<=k;j++)
		{
			if((1<<j-1)&i)
			{
				t--;
				answer+=c[j];
				for(register int l=1;l<=n;l++)
				{
					e.push_back({n+j,l,d[j][l]});
				}
			}
		}
		if(answer>ans)continue;
		sort(e.begin(),e.end(),cmp);
		for(register int j=0;j<e.size();j++)
		{
			ll q=findfa(e[j].q);
			ll w=findfa(e[j].w);
			if(q!=w)
			{
				answer+=e[j].e;
				if(answer>ans)break;
				fa[q]=w;
				t++;
				if(t+1==n)break;
			}
		}
		if(answer<ans)ans=answer;
	}
	cout<<ans;
	return 0;
}
