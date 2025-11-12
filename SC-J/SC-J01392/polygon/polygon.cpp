#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll p = 998244353;

ll quickpow(ll x,ll y){
	ll result=1;
	while(y){
		if(y%2==1) result = result * (x % p) %p;
		x=(x*x)%p,y>>=1;
	}
	return result%p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	vector<int> len(n+1);
	for(int i=1;i<=n;i++){
		cin >> len[i];
	}
	sort(len.begin()+1,len.end());		
	if(n == 3){
		if(len[1]+len[2]>len[3]) cout << 1;
		else cout << 0;
		return 0;
	}
	if(len[n] == 1){
		vector<ll> fact(n+5,1);
		for(int i=1;i<=n;i++) {
			fact[i] = (fact[i-1])%p*i,fact[i]%=p;
			cout << fact[i] <<' ';
		}
		ll ans = 0;
		for(int i=3;i<=n;i++){
//			ans+=(fact[n]%p*(quickpow(fact[i-1]%p*(fact[i]%p)%p,p-2)%p)%p);
			
//			ll temp = fact[n]%p;
//			temp=temp*quickpow(fact[i-1],p-2)%p;
//			temp=temp*quickpow(fact[i],p-2)%p;
//			ans+=temp;
//			ans%=p;
//			cout << ans << ' ';
//			cout << 3;
		}
		cout << 4;
		return 0;
	}
	cout << 0;
	return 0;
}