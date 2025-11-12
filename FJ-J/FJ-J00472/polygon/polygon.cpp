#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n, a[5500], ans=0;
bool fl1=true;
ll jie(ll n){
	ll sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	return sum;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1){
			fl1=false;
		}
	}
	sort(a+1, a+n+1);
	if(fl1 || a[1]==a[n]){
		for(ll i=3;i<=n;i++){
			ans+=jie(n)/(jie(i)*jie(n-i));
			ans%=mod;
		}
		cout << ans%mod << '\n';
		return 0;
	}
	if(n<3){
		cout << 0 << '\n';
		return 0;
	}
	if(n==3){
		sort(a+1, a+n+1);
		if(a[1]+a[2]>a[3]){
			cout << 1 << '\n';
			return 0;
		}else{
			cout << 0 << '\n';
			return 0;
		}
	}
	return 0;
}
