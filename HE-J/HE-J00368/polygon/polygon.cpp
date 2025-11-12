#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//´ËÎª±©Á¦ 
const ll INF = 998244353;
ll n;
ll a[5001];
ll ans = 0;
ll top = 0;

ll jiecheng(ll x){
	if(x==0){
		return 1;
	}
	return x*jiecheng(x-1);
}
inline void solve(ll x,ll ma,ll sum){
	if(x>n){
		if(sum>2*ma){
			ans++;
			ans%=INF;
		}
		return;
	}
	solve(x+1,max(a[x],ma),sum+a[x]);
	solve(x+1,ma,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	solve(1,0,0);
	printf("%lld",ans%INF);
	return 0;
}

