#include <functional>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<long long,long long> pll;
long long n,m,k,u,v,w,s,sz,cnt,ans=LLONG_MAX,c[15],a[15][20005],d[20005],i,j;
vector<pll> g[20005];
bool f,b[20005];
priority_queue<pll,vector<pll>,greater<pll> > pq;
int main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;++i) scanf("%lld%lld%lld",&u,&v,&w),g[u].push_back({w,v}),g[v].push_back({w,u});
	for(i=1;i<=k;++i) {
		scanf("%lld",&c[i]);
		for(j=1;j<=n;++j) scanf("%lld",&a[i][j]);
	}
	for(i=1;i<=k;++i)
		for(j=1;j<=n;++j) {
			g[n+i].push_back({a[i][j],j});
			g[j].push_back({a[i][j]+c[i],n+i});
		}
	pq.push({0,1}),s=cnt=0;
	while(!pq.empty()&&cnt<n) {
		long long x=pq.top().second,p=pq.top().first;
		pq.pop();
		if(b[x]) continue;
		b[x]=true,s+=p;
		if(x<=n) ++cnt;
		for(pll y:g[x]) pq.push(y);
	}
	printf("%lld",s);
	return 0;
}
