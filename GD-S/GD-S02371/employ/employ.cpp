#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int M = 998244353;
	int ans = 1;
	int i=1;
	while(i<=m){
		ans*=(i++);
	}
	ans%=M;
	cout << ans;
	
	return 0;
}
