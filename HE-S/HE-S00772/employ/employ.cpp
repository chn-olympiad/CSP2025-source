/*
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion && ulimit -v 1024000 && time ./%< && size %<
clear && ulimit -s 1024000 && g++ % -o %< -O2 -std=c++14 -DLOCAL -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined -g && ./%<
echo && cat out.out && echo
*/
#include <bits/stdc++.h>
using namespace std;
using llt = long long;
using llf = long double;
using ull = unsigned long long;
template<class T> void Cmin(T &a, T b){ if(a > b) a = b; }
template<class T> void Cmax(T &a, T b){ if(a < b) a = b; }
#define endl '\n'
#ifdef LOCAL
FILE *InFile = freopen("in.in", "r", stdin), *OutFile = freopen("out.out", "w", stdout);
#else
FILE *InFile = freopen("employ.in", "r", stdin), *OutFile = freopen("employ.out", "w", stdout);
#endif

const int N = 503, MOD = 998244353;
int n, m, _p[N]; char s[N];


int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s + 1;
	for(int i = 1; i <= n; ++i) cin >> _p[i];
	if(n == m && n > 10){
		bool f = 1;
		for(int i = 1; i <= n; ++i) f &= (_p[i] && s[i] == '1');
		if(f){
			int ans = 1;
			for(int i = 1; i <= n; ++i)
				ans = 1ll * ans * i % MOD;
			cout << ans << endl;
		}else cout << 0 << endl;
		return 0;
	}
	vector<int> id(n); iota(id.begin(), id.end(), 1);
	int ans = 0;
	do{
		int c = 0;
		for(int i = 1; i <= n; ++i) if(s[i] == '0' || _p[id[i - 1]] <= c) ++c;
		if(n - c >= m) ++ans;
	}while(next_permutation(id.begin(), id.end()));
	cout << ans;
}
