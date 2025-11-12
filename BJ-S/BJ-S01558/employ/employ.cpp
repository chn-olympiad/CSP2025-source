#include<bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod = 998244353;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.ans","w",stdout);
	int n,m;
	cin >> n >> m;
	ll ans = 1;
	for(int i = n,j = 1;j <= m;i--,j++){
		ans *= i,ans %= mod;
	}
	cout << ans;
	return 0;
}

