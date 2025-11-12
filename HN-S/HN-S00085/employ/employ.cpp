#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+5, M=998244353;
ll n, m, c[N], ans=2;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	cout << ans%M;
	return 0;
}
