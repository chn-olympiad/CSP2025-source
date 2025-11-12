//GZ-S00080 华东师范大学附属贵阳学校 向耕立
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_N=1e6+10;
ll n,m,k;
typedef struct node{ll a,b,c;}node;
vector<vector<node> > vec(MAX_N);
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ll n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=0,u,v,w;i<n;i++){
		scanf("%lld %lld %lld",&u,&v,&w);
		//printf("%lld\n",u);
		vec[u].push_back({v,w,0});
		vec[v].push_back({u,w,0});
	}	
	ll ans=0,v;
	for(ll i=1,now;i<=n;i++){
		now=10000000010;
		for(const auto &[a,b,c]:vec[i]){
			if(!c&&b<now){
				now=b;
				v=a;
			}
		}
		for(ll j=0;j<vec[i].size();j++){
			if(v==vec[i][j].a){
				vec[i][j].c=1;
				vec[vec[i][j].b][vec[i][j].a].c=1;
				break;
			}
		}
		ans+=now;
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}