#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n,m;
ll quick_pow(ll a,ll b){
	ll res=1,x=1;
	while(b!=0){
		if(b&1==1){
			res=(res+x)%mod;
			x*=a;
		}
		b>>1;
	}
	return res;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cout<<quick_pow(2,m)%mod;
	return 0;
}
