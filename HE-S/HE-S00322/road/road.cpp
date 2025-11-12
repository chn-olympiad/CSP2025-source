#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e4+4;
struct edge{
	int u,v;
	long long w;
};
int n,m,k;
int fa[N];
long long a[N];
vector<edge> e;
int find(int t)
{
	if(fa[t]==t) return t;
	fa[t]=find(fa[t]);
	return fa[t];
}
void link(int a,int b)
{
	fa[find(a)]=find(b);
}
bool c(edge a,edge b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		long long w;
		scanf("%d%d%d",&u,&v,&w);
		edge t;
		t.u=u;
		t.v=v;
		t.w=w;
		e.push_back(t);
	}
	for(int i=1;i<=k;++i)
	{
		long long tc;
		scanf("%lld",&tc);
		for(int j=1;j<=n;++j)
			scanf("%lld",&a[j]);
		for(int tu=1;tu<=n;++tu)
			for(int tv=tu+1;tv<=n;++tv)
			{
				edge t;
				t.u=tu;
				t.v=tv;
				t.w=tc+a[tu]+a[tv];
				e.push_back(t);
			}
	}
	sort(e.begin(),e.end(),c);
	long long ans=0;
	int l=e.size(),cnt=0;
	for(int i=0;i<l&&cnt<n;++i)
	{
		edge it=e[i];
		if(find(it.u)!=find(it.v))
		{
			link(it.u,it.v);
			ans+=it.w;
			cnt++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
