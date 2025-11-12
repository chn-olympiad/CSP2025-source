#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,ll> Pair;
const ll N=100005;
ll tn,pn,ans,v[N][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&tn);
	for(;tn>0;tn--){
		ans=0;
		priority_queue<ll,vector<ll>,greater<ll> > q[3];
		scanf("%lld",&pn);
		for(ll i=1;i<=pn;i++){
			scanf("%lld%lld%lld",&v[i][0],&v[i][1],&v[i][2]);
		}
		for(ll i=1;i<=pn;i++){
			ll n1=0,n2=1,n3=2;
			if(v[i][n2]<v[i][n3]){
				swap(n2,n3);
			}
			if(v[i][n1]<v[i][n2]){
				swap(n1,n2);
			}
			if(v[i][n2]<v[i][n3]){
				swap(n2,n3);
			}
			if(q[n1].size()<pn/2){
				ans+=v[i][n1];
				q[n1].push(v[i][n1]-v[i][n2]);
			}else{
				if(v[i][n1]-q[n1].top()>v[i][n2]){
					ans+=v[i][n1]-q[n1].top();
					q[n1].pop();
					q[n1].push(v[i][n1]-v[i][n2]);
				}else{
					ans+=v[i][n2];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
