#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x = 0, f = 1; char ch = getchar();while(ch > '9' or ch < '0'){if(ch == '-'){f = -1;}ch=getchar();}while(ch >= '0' and ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}return x * f;}
inline void write(int x){if(x < 0){putchar('-');x = -x;}if(x >= 10){write(x/10);}putchar(x % 10 + '0');}
#define pb emplace_back
#define put() putchar(' ')
#define endl puts("")
const int MAX = 505;
const int mod = 998244353;

int a[MAX], c[MAX];

namespace subtask1{
	int p[MAX];
	void solve(int n, int m){
		int ans = 0;
		for(int i = 1; i <= n; i++)	p[i] = i;
		do{
			int cnt = 0, cnt2 = 0;
			for(int i = 1; i <= n; i++){
				if(a[i] == 0){
					cnt2++;
				}else{
					if(cnt2 >= c[p[i]]){
						cnt2++;
					}else{
						cnt++;
					}
				}
			}
			// ans++;
			if(cnt >= m){
				ans++;
			}
		}while(next_permutation(p + 1, p + n + 1));
		write(ans % mod), endl;
	}
}

namespace subtask2{
	int cnt[MAX];
	int f[MAX][MAX][MAX];
	void solve(int n, int m){
		for(int i = 1; i <= n; i++)	cnt[c[i]]++;
		// f[n + 1][n] = 1;
		f[0][cnt[0]][n - cnt[0]] = 1;
		int cnt2 = cnt[0];
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int k = 0; k <= n; k++){	
					int sum = n - i + 1;
					if(a[i] == 0){
						if(j + cnt[i] <= n and k - 1 - cnt[i] >= 0){
							f[i][j + cnt[i]][k - 1 - cnt[i]] += f[i - 1][j][k] * k % mod;
							f[i][j + cnt[i]][k - 1 - cnt[i]] %= mod;
						}
						if(j + cnt[i] - 1 <= n and k - cnt[i] >= 0){
							f[i][j + cnt[i] - 1][k - cnt[i]] += f[i - 1][j][k] * (j) % mod;
							f[i][j + cnt[i] - 1][k - cnt[i]] %= mod;
						}	
					}else{
						if(j + cnt[i] - 1 <= n and k - cnt[i] >= 0){
							f[i][j + cnt[i] - 1][k - cnt[i]] += f[i - 1][j][k] * j % mod;
							f[i][j + cnt[i] - 1][k - cnt[i]] %= mod;
						}
					}
				}
			}
		}
		// int cnt = 0;
		// for(int i = 0; i <= n; i++)	cnt += f[n][i]
		// write(f[1][0]), endl;
		// write(f[n][0]), endl;
		// write(cnt[n]), endl;
		// write(f[n][n - 1]), endl;
		// write(f[n - 1][n - 2]), endl;
		// write(f[n + 1][n]), endl;
		// write(f[1][0]), endl;
		
		// for(int i = 0; i <= n; i++){
			// for(int j = 0; j <= n; j++){
				// write(f[2][i][j]), put();
			// }
			// endl;
		// }
		int ans = 1;
		for(int i = 1; i <= n; i++)		ans = ans * i % mod;
		write((ans - f[n][0][0] + mod) % mod), endl;
	}
}

void solve(){
	int n = read(), m = read();	
	for(int i = 1; i <= n; i++){
		char ch = getchar();
		while(ch != '0' and ch != '1')	ch = getchar();
		a[i] = ch - '0';
	}
	for(int i = 1; i <= n; i++){
		c[i] = read();
	}
	// subtask1::solve(n, m);
	// subtask2::solve(n, m);
	// if(m == 1)
	if(n <= 10)	subtask1::solve(n, m);
	else if(m == 1)	subtask2::solve(n, m);
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int t = 1;
	while(t--)	solve();
	return 0;
}