#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e6+7;
ll n,m,k,fa[M],c[17],ans,vis[17],cnt[17],sum[17];
struct node{
	ll u,v,w;
	bool operator<(const node n2){
		return w<n2.w;
	}
};
vector<node>e;
ll fd(ll x){
	return fa[x]==x?x:(fa[x]=fd(fa[x]));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k); 
	while(m--){
		node n3;
		scanf("%lld %lld %lld",&n3.u,&n3.v,&n3.w);
		e.emplace_back(n3);
	}
	for(int i=1;i<=n+k;i++)fa[i]=i; 
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			node n3;
			scanf("%lld",&n3.w);
			n3.u=i+n;n3.v=j;n3.w+=c[i];
			e.emplace_back(n3);
		}
	}
	sort(e.begin(),e.end());
	ll len=e.size();
	for(int i=0;i<len;i++){
		
		ll u=e[i].u,v=e[i].v,w=e[i].w;
		ll fu=fd(u),fv=fd(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		ans+=w;
		if(u>n){
			sum[u-n]+=w;
			cnt[u-n]++;
		}
		//printf("<%lld-%lld(%lld)>\n",u,v,w); 
	}
	for(int i=1;i<=k;i++){
		if(cnt[i]==1)ans-=sum[i];
		else if(cnt[i]>1)ans-=c[i]*(cnt[i]-1);
	}
	cout<<ans;
	return 0;
}
