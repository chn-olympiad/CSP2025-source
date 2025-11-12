#include <iostream>
using namespace std;
using ll=long long;
const ll mod=998244353;
ll f(ll x){
	if(x<=1){
		return 1;
	}
	return x*f(x-1LL)%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
} 
