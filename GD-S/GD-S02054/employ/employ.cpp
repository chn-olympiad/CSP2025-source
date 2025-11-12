#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int, int>
#define debug(x) cerr << #x << ": " << x << "\n"
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, a[507], p[507];
string s;
void solve(){
	int sum = 0;
	do{
		int get = 0, no = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '0') no++;
			else if(a[p[i]] > no) get++;
			else if(a[p[i]] <= no) no++;
		}
		if(get >= m) sum++;
		sum %= mod;
	}while(next_permutation(p + 1, p + 1 + n));
	cout << sum;
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	s = ' ' + s;
	for(int i = 1;i <= n;i++) cin >> a[i], p[i] = i;
	solve();
}
