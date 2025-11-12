#include <iostream>
#include <cstdio>

using namespace std;
const int N = 505, M = 18, mod = 998244353;
typedef long long ll;
typedef pair <int, int> pll;
int n, m, v[N];
char c[N];
ll cnt, f[1 << M][M + 1];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	if(n <= 18){
		f[0][0] = 1;
		for(int i = 0; i < (1 << n); i++){
			int len = 0;
			for(int j = 0; j < n; j++)
				if(i & (1 << j)) len++;
			for(int j = 0; j < n; j++){
				if(!(i & (1 << j))) continue;
				for(int k = 0; k <= len - 1; k++)
					f[i][k + (c[len - 1] == '1' && len - k - 1 < v[j])] = (f[i][k + (c[len - 1] == '1' && len - k - 1 < v[j])] + f[i ^ (1 << j)][k]) % mod;
			}
		}
		for(int i = m; i <= n; i++) cnt = (cnt + f[(1 << n) - 1][i]) % mod;
		cout << cnt << "\n";
	}else{
		cout << "0\n";
	}
	return 0;
}
