#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int tt=510,mod=998244353;
ll c[tt];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >>n>>m;
	string s;
	cin >>s;
	ll idx=0;
	for(ll i=1;i<=n;i++){
		cin >>c[i];
	}
	ll cnt=1;
	for(ll i=n-1;i>=1;i--){
		cnt=cnt*(i+mod)%mod;
	}
	cout <<(cnt*n+mod)%mod;
	return 0;
}
