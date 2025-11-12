#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 988244353;
int w[550] , p[550];
string a;
int n , m , ans;
signed main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == '0') w[i+1] = w[i]+1;
		else w[i+1] = w[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin>>p[i];
	}
	ans = 1;
	sort(p+1 , p+1+n);
	for(int i = n ; i >= 1 ; i--){
		ans = ((ans%mod) * (i%mod))%mod;
	}
	cout<<ans;
	return 0;
}
