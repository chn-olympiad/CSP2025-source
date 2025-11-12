#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m;
long long ans = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		ans *= n + 1 - i;
		ans %= mod;
	}
	cout<<ans;
	return 0;
}

