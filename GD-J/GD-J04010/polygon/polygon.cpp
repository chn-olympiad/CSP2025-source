#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const LL MAXN = 5e3+5, MOD = 998244353;
LL n, ans, cnt1, invn, a[MAXN], nj[MAXN], in_nj[MAXN];
bool isall;

bool cmp(LL x, LL y) {
	return x > y;
}

LL mfp(LL x, LL y) { // mod MOD下的x^y 
	LL res = 1, k = x;
	while (y) {
		if (y&1) res = (res*k)%MOD;
 		y>>=1;
 		k = (k*k)%MOD;
	 } 
 	return res;
}

LL chs(LL k, LL x) { // 在k个数里任选至多x个数 
	LL res = 0;
	for (LL i = 3; i<=x; i++) { // 直接计算 
		res += (((nj[k]*in_nj[i])%MOD)*in_nj[k-i])%MOD; 
	}
	return res;
}

LL dfs(LL mx, LL x, LL s, LL cnt) { // 选取的最大值为mx，现在到了x处，之前的总和为s，选了cnt个 
	if (x > n){
		if (s > mx<<1) return 1;
		else return 0;
	} 
//	if (s > mx<<1 && cnt >= 3) {
//		return (1+chs(n-x+1, n-x+1))%MOD;
//	}
//	LL res = 0;
	LL res = (dfs(mx, x+1, s, cnt)+dfs(mx, x+1, s+a[x], cnt+1))%MOD;
	return res;
}

// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	isall = true;
	for (LL i = 1; i<=n; i++) {
		cin >> a[i];
		if (i>1 && a[i] != a[i-1]) isall = false;
	}
	if (isall) {
		invn = mfp(n, MOD-2);
		nj[0] = in_nj[0] = 1, isall = true;
		for (LL i = 1; i<=n; i++) {
			nj[i] = (nj[i-1]*i) %MOD;
			in_nj[i] = mfp(nj[i], MOD-2);
		}
		ans = chs(n, n);
		cout << ans;
		return 0;
	}
	sort(a+1, a+1+n, cmp);
	for (LL i = 1; i<=n-2; i++)
		ans = (ans+dfs(a[i], i+1, a[i], 1))%MOD;
	cout << ans << endl;
	return 0;
} 
