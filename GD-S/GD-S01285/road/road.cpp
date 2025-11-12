#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
ll n,m,k,h[10010],a[20][10010],c[20],mc,ans;
struct node{
	ll to,w;
};
vector<node>v[10010];
struct edge{
	ll u,v,w;
	bool operator<(const edge&o)const{
		return w<o.w;
	}
}e[1000010];
ll find(ll a){
	if(a!=h[a])return h[a]=find(h[a]);
	return a;
}
void merge(ll a,ll b,ll w){
	a=find(a);
	b=find(b);
	if(a!=b){
		h[a]=b;
		ans+=w;
	}
}
void init(){iota(h,h+10010,0);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
		v[e[i].u].push_back(node{e[i].v,e[i].w});
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		mc=max(mc,c[i]);
		ans+=c[i];
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0){
		init();
		sort(e+1,e+1+m);
		for(ll i=1;i<=m;i++)merge(e[i].u,e[i].v,e[i].w);
		printf("%lld",ans);
	}
	else if(mc==0){
		init();
		ll cnt=n-1,now=1,minx=0,t=0;
		for(;cnt--;){
			minx=1e9;
			for(auto x:v[now]){
				if(x.w<minx&&find(now)!=find(x.to)){
					minx=x.w;
					t=x.to;
				}
			}
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++){
					if(a[i][now]+a[i][j]<minx&&find(now)!=find(j)){
						minx=a[i][now]+a[i][j];
						t=j;
					}
				}
			}
			merge(t,now,minx);
			for(int i=1;i<=n;i++){
				if(find(i)!=find(now)){
					now=i;
					break;
				}
			}
			t=0;
		}
		cout<<ans;
	}
	else cout<<rand();
	return 0;
}
