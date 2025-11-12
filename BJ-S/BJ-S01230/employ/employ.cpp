// Calm down.
// Think TWICE, code ONCE.
#include<bits/stdc++.h>
#define pb push_back
#define popcnt __builtin_popcountll
#define debug printf("Passed line %d\n", __LINE__)

using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
	x = 0; bool F = 0; char c = getchar();
	for (;!isdigit(c);c = getchar()) F |= (c == '-');
	for (;isdigit(c);c = getchar()) x = x*10+(c^48);
	if (F) x = -x;
}

template<typename T1, typename ...T2> inline void read(T1 &x, T2 &...y){read(x), read(y...);}

inline void Get(char &c){do{c = getchar(); } while (!isdigit(c));}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = (1<<18)+5, M = 20, K = 510;
const ll MOD = 998244353;
int flag[K], c[K], n, m;
ll dp[N][M];

inline void solve1(){
	ll ans = 1;
	for (int i = 1;i<=n;i++){
		if (!flag[i-1] || !c[i-1]) ans = 0;
		(ans *= i) %= MOD;
	}
	printf("%lld\n", ans);
}

int add[N], Minus[N];

inline void solve2(){
	ll all = 1, ans = 1;
	for (int i = 1;i<=n;i++) (all *= i) %= MOD;
	for (int i = 0;i<n;i++){
		add[flag[i] ? i : n]++;
		Minus[c[i]]++;
	}
	int tot = 0;
	for (int i = n;i>=0;i--){
		tot += add[i];
		while (Minus[i]--) (ans *= tot) %= MOD, tot--;
	}
	printf("%lld\n", (all+MOD-ans)%MOD);
}

int main(){
	// freopen("input.txt", "r", stdin); cerr << "----------------------------------- Program output -----------------------------------\n";
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n, m); char ch;
	for (int i = 0;i<n;i++) Get(ch), flag[i] = ch-'0';
	for (int i = 0;i<n;i++) read(c[i]);
	if (m == n){solve1(); return 0;}
	if (m == 1){solve2(); return 0;}
	dp[0][0] = 1; int t, New;
	for (int i = 0;i<(1<<n);i++){
		t = popcnt(i);
		for (int j = 0;j<=t;j++){
			for (int k = 0;k<n;k++){
				if (i&(1<<k)) continue;
				New = i|(1<<k);
				if (flag[t] && t-j<c[k]) (dp[New][j+1] += dp[i][j]) %= MOD;
				else (dp[New][j] += dp[i][j]) %= MOD;
			}
		}
	}
	ll ans = 0;
	for (int i = m;i<=n;i++) ans += dp[(1<<n)-1][i];
	printf("%lld\n", ans%MOD);
	return 0;
}
/*
self check:
1. freopen
2. long long
3. size of array
4. code for testing
*/