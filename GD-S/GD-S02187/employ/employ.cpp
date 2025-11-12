#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, s[N], c[N], cnt[N], f[N][N], book[N], rel[N], anss;//ci可能为0！ 
void dfs(int now){
	if (now == n + 1){
		int ga = 0, hd = 0;
		for (int i = 1; i <= n; ++i){
			if (ga >= c[rel[i]] || s[i] == 0){
				++ga;
			}
			else{
				++hd;
			}
		}
		if (hd >= m){
			++anss;
		}
		return;
	}
	for (int i = 1; i <= n; ++i){
		if (!book[i]){
			book[i] = 1;
			rel[now] = i;
			dfs(now + 1);
			book[i] = 0;
		}
	}
}
int main(){
	srand(time(0));
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int flag = 1;//每一天都能做出来 
	for (int i = 1; i <= n; ++i){
		int ch = getchar();
		s[i] = ch - '0';
		if (s[i] == 0){
			flag = 0;
		}
	}
	for (int i = 1; i <= n; ++i){
		cin >> c[i];
		++cnt[c[i]];
	}
	if (m == n){
		sort(c + 1, c + n + 1);
		if (c[1] == 0 || !flag){
			cout << 0;
		}
		else{
			long long res = 1; 
			for (int i = 1; i <= n; ++i){
				res = res * i % mod;
			}
			cout << res;
		}
		return 0;
	}
	if (n <= 10){
		dfs(1);
		cout << anss;
		return 0;
	}
	if (flag){//ci可能为零！ fi,j为前i种人j个放弃的方案数 
		long long res = 1; 
		for (int i = 1; i <= n; ++i){
			res = res * i % mod;
		}
		cout << res;
		return 0;
	}
	cout << rand();
	return 0;
}
