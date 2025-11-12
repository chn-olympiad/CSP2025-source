#include <bits/stdc++.h>
#define re register
#define int long long
#define Add(a,b) (((a) + (b)) % mod)
#define Sub(a,b) (((a) - (b) + mod) % mod)
#define Mul(a,b) ((a) * (b) % mod)
#define chAdd(a,b) (a = Add(a,b))
#define chMul(a,b) (a = Mul(a,b))

using namespace std;

const int N = 510;
const int mod = 998244353;
int n,m;
int c[N],fac[N];
char s[N];

inline int read(){
	int r = 0,w = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') w = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		r = (r << 1) + (r << 3) + (c ^ 48);
		c = getchar();
	}
	return r * w;
}

inline void init(int n){
	fac[0] = 1;
	for (re int i = 1;i <= n;i++) fac[i] = Mul(fac[i - 1],i);
}

namespace Sub1{
	const int N = 24,M = (1 << 18) + 10;
	int dp[M][N];
	
	inline void solve(){
		int ans = 0; dp[0][0] = 1;
		for (re int st = 1;st < (1 << n);st++){
			int cnt = __builtin_popcount(st);
			for (re int i = 0;i < n;i++){
				for (re int j = 1;j <= n;j++){
					if ((st >> (j - 1)) & 1){
						if (s[cnt] == '1' && cnt - 1 - i < c[j]) chAdd(dp[st][i + 1],dp[st ^ (1 << (j - 1))][i]);
						else chAdd(dp[st][i],dp[st ^ (1 << (j - 1))][i]);
					}
				}
			}
//			for (re int i = 0;i <= n;i++){
//				if (dp[st][i]) cerr << st << " " << i << " " << dp[st][i] << " ???\n";
//			}
		}
		for (re int i = m;i <= n;i++) chAdd(ans,dp[(1 << n) - 1][i]);
		printf("%lld\n",ans);
	}
}

namespace Sub2{
	int cnt[N];
	
	inline void solve(){
		int ans = 1,tot = 0;
		for (re int i = 1;i <= n;i++) cnt[c[i]]++;
		for (re int i = 1;i <= n;i++){
			if (s[i] == '1'){
				int res = 0;
				for (re int j = 0;j < i;j++) res += cnt[j];
				cnt[i - 1]--; chMul(ans,res);
			}
			else tot++;
		} chMul(ans,fac[tot]);
		printf("%lld\n",Sub(fac[n],ans));
	}
}

namespace Sub3{
	inline void solve(){
		for (re int i = 1;i <= n;i++){
			if (s[i] == '0' || !c[i]) return puts("0"),void();
		} printf("%lld\n",fac[n]);
	}
}

namespace Sub4{
	int r,cnt[N],dp[2][N];
	vector<vector<int>> v[2][N];

	inline void solve(){
		int ans = 0,cnt0 = 0,cnt1 = 0;
		for (re int i = 1;i <= n;i++) cnt[c[i]]++;
		dp[0][0] = 1; v[0][0].push_back(vector<int>());
		for (re int i = 0;i <= n;i++) v[0][0].front().push_back(cnt[i]);
		for (re int i = 1;i <= n;i++){
			if (s[i] == '1'){
				r ^= 1;
				for (re int j = 0;j <= n;j++) dp[r][j] = 0;
				for (re int j = 0;j <= n;j++) v[r][j].clear();
				for (re int j = 0;j <= cnt1;j++){
//					cerr << i << " " << j << " " << dp[r ^ 1][j] << " ???\n";
					for (vector<int> t:v[r ^ 1][j]){
						if (j < cnt1){
							int tot = 0;
							for (re int k = 0;k <= cnt0 + j;k++) tot += t[k];
							vector<int> tmp = t; tmp[cnt0 + j]--;
							v[r][j + 1].push_back(tmp);
							chAdd(dp[r][j + 1],Mul(dp[r ^ 1][j],tot));
						} int tot = 0;
						for (re int k = cnt0 + j + 1;k <= n;k++) tot += t[k];
						vector<int> tmp = t; tmp[cnt0 + j + 1]--;
						v[r][j].push_back(tmp);
//						cerr << i << " " << j << " " << tot << " !!!\n";
//						for (int x:t) cerr << x << " "; cerr << "\n";
						chAdd(dp[r][j],Mul(dp[r ^ 1][j],tot));
					}
				} cnt1++;
			}
			else cnt0++;
		}
		// cnt1 - m >= j
		for (re int i = 0;i <= cnt1 - m;i++) chAdd(ans,dp[r][i]);
		printf("%lld\n",Mul(ans,fac[cnt0]));
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read(),m = read();
	scanf("%s",s + 1); init(n);
	for (re int i = 1;i <= n;i++) c[i] = read();
	int tot = 0;
	for (re int i = 1;i <= n;i++) tot += (s[i] == '1');
	if (tot < m) return puts("0"),0;
//	Sub4::solve(); return 0;
	if (n <= 18) Sub1::solve();
	else if (m == 1) Sub2::solve();
	else if (m == n) Sub3::solve();
	else Sub4::solve();
	return 0;
}

/*
10 10
1111111111
6 1 4 2 1 2 5 4 3 3
*/
