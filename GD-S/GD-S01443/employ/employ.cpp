#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

const int N = 20, M = (1 << 18) + 10, mod = 998244353;
int n, m, c[N], f[M][N], ans;
string s; bool vis[M][N];

int lb(int x){
	int cnt = 0;
	while(x){
		cnt++;
		x -= x & -x;
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) cin >> c[i];
	f[0][0] = 1; vis[0][0] = 1;
	for(int i = 0; i < (1 << n); i++){
		int rd = lb(i);
		for(int k = 0; k <= n; k++){
			if(!vis[i][k]) continue;
			for(int j = 0; j < n; j++){
				if(((1 << j) & i) == 0){
					if(k >= c[j] || s[rd] == '0') f[i^(1 << j)][k+1] = (f[i^(1 << j)][k+1] + f[i][k]) % mod;
					else f[i^(1 << j)][k] = (f[i^(1 << j)][k] + f[i][k]) % mod;
					if(k >= c[j] || s[rd] == '0') vis[i^(1 << j)][k+1] = 1;
					else vis[i^(1 << j)][k] = 1;
				}
			}
		}
	}
	for(int i = 0; i <= n-m; i++){
		ans = (ans + f[(1 << n)-1][i]) % mod;
	}
	cout << ans;
	return 0;
}
