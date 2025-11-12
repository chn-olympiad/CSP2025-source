#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20;
struct road{
	ll u,v,w;
}a[N];
ll n,m,k,fa[N],ans,sum,cost[N];
vector<road>ve[15];
ll find(ll x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(road x,road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k+k*n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	if(k==0){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			ll u=find(a[i].u),v=find(a[i].v);
			if(u==v) continue;
			ans+=a[i].w;
			fa[u]=v;
			sum++;
			if(sum==n-1) break;
		}
		cout<<ans;
		return 0;
	}
	ll cnt=m,city=n;
	for(int i=1;i<=k;i++){
		cin>>a[++cnt].w;a[cnt].v=0,a[cnt].u=++city;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[++cnt].w);a[cnt].u=city,a[cnt].v=j;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		ll p=a[i].u,q=a[i].v;
		ll u=find(a[i].u),v=find(a[i].v);
		if(u==v) continue;
		ans+=a[i].w;
		fa[u]=v;
		if(p>0&&p<=n&&q>0&&q<=n) sum++;
		if(sum==n-1) break;
	}
	cout<<ans;
	return 0;
}
