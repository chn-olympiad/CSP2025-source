#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long 
#define pii pair<int, int>
#define mse(x, y) memset(x, y, sizeof x)
#define mcp(x, y) memcpy(x, y, sizeof x)
#define viclear(x) vector<int>().swap(x)
#define vpiiclear(x) vector<pii>().swap(x)
#define rep(x, l, r) for(int x = l; x <= r; x++)
#define drep(x, r, l) for(int x = r; x >= l; x--)
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
using namespace std;

const int MAXN = 20, MAXM = (1 << 18) + 4, mod = 998244353;
int n, m, a[MAXN], c[MAXN], dp[MAXM][MAXN], G[3000005];
char In;

int Get(int x){
	int res = 0;
	while(x){
		if(x & 1) res++;
		x >>= 1;
	}
	return res;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	FASTIO;
	cin >> n >> m;
	rep(i, 0, (1 << n) - 1) G[i] = Get(i);
	rep(i, 1, n) cin >> In, a[i] = In - '0';
	rep(i, 1, n) cin >> c[i];
	dp[0][0] = 1; 
	rep(msk, 0, (1 << n) - 1){
		int i = G[msk]; 
		rep(j, 0, i){
			rep(k, 1, n){
				if((msk >> (k - 1)) & 1) continue;
				dp[msk | (1 << (k - 1))][j + (c[k] > (i - j) && a[i + 1])] += dp[msk][j];
				dp[msk | (1 << (k - 1))][j + (c[k] > (i - j) && a[i + 1])] %= mod;
			}
		}
	}
	int ans = 0;
	rep(i, m, n) rep(msk, 0, (1 << n) - 1) ans += dp[msk][i], ans %= mod;
	cout << ans;
    return 0;
}

