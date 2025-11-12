#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct edge{
	int u,v,w;
};
vector<edge> e(1000005);
int n,m,k,a[20][10005],c[20],b[20],f[10020];
ll sum,ans=1e18;
void init()
{
	for(int i=1;i<=n+k;i++)
		f[i]=i;
}
int find(int x)
{
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
void kruskal()
{
	init();
	for(auto i:e)
	{
		int fu=find(i.u),fv=find(i.v);
		if(fu==fv) continue;
		if(i.u>n && b[i.u-n]==0) continue;
		if(i.v>n && b[i.v-n]==0) continue;
		sum+=i.w;
		f[fu]=f[fv];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		edge x;
		cin>>x.u>>x.v>>x.w;
		e.push_back(x);
	}
	int ck=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) ck=1;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			e.push_back({n+i,j,a[i][j]});
		}
	}
	sort(e.begin(),e.end(),cmp);
	if(ck==0)
	{
		for(int i=1;i<=k;i++) b[i]=1;
		kruskal();
		cout<<sum;
		return 0;
	}
	for(int q=0;q<(1<<k);q++)
	{
		sum=0;
		for(int i=0;i<k;i++)
		{
			b[i+1]=0;
			if(q&(1<<i))
			{
				sum+=c[i+1];
				b[i+1]=1;
			}
		}
		kruskal();
		ans=min(ans,sum);
	}
	cout<<ans;
}
