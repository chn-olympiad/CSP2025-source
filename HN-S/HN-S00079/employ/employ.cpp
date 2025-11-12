#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n,ans = 1;
	cin >> n;
	for(int i = 1;i <= n;i++){
		ans = (ans * i) % 998244353;
	}
	cout << ans;
	return 0;
}
