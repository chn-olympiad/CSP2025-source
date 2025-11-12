#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,v[20],ans=10000000000000000,tf[15];
ll to[10020];
struct node{
	ll to,v;
};
vector<node> vc[10020];
bool cmp(ll x,ll y){
	if(to[x]==-1) return false;
	if(to[y]==-1) return true;
	return to[x]<to[y];
}
ll mntr(){
	ll sum=0;
	for(ll i=1;i<=k;i++){
		if(tf[i]) sum+=v[i];
	}
	vector<ll> h;
	for(ll i=1;i<=n+k;i++){
		if(i<=n||tf[i-n]){
			h.push_back(i);
		}
	}
	bool vv[10020];
	memset(vv,0,sizeof vv);
	memset(to,0x3f,sizeof to);
	vv[1]=1;to[1]=0;
	while(h.size()){
		sort(h.begin(),h.end(),cmp);
		ll top=h[0];
		sum+=to[top];
		to[top]=-1;
		h.erase(h.begin());
		for(int i=0;i<vc[top].size();i++){
			to[vc[top][i].to]=min(to[vc[top][i].to],vc[top][i].v);
		}
	}
	return sum;
}
void dfs(ll x){
	if(x>k){
		ans=min(ans,mntr());
	}else{
		tf[x]=1;
		dfs(x+1);
		tf[x]=0;
		dfs(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll x,y,z,p,q;
		scanf("%lld %lld %lld",&x,&y,&z);
		vc[x].push_back((node){y,z});
		vc[y].push_back((node){x,z});
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&v[i]);
		for(int j=1;j<=n;j++){
			ll x;
			scanf("%lld",&x);
			vc[i+n].push_back((node){j,x});
			vc[j].push_back((node){i+n,x});
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
//O((2**k)nm)
