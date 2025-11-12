#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+5,mod=998244353;
using namespace std;
ll n;
ll z;
ll q_pow(ll a,ll k){
	ll res=1;
	while(k){
		if(k & 1) res=(res*a)%mod;
		a=(a*a)%mod;
		k>>=1;
	}
	return res;
}
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
		return 0; 
	}
	cout<<0;
	return 0;
}
