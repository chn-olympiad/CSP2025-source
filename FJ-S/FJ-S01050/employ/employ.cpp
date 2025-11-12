#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int N, M, C[505], ps[505], pt[505];
char S[505];
ll ans, F[505], f[505], inv[505], aft[1 << 18];
bool st[505];
int p1[505], G[505], cnt;

ll power(ll x, ll y) {
	if(!y)
		return 1;
	ll w = power(x * x % MOD, y >> 1);
	if(y & 1)
		w = w * x % MOD;
	return w;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &N, &M);
	F[0] = 1;
	for(int i = 1; i <= N; i ++)
		F[i] = F[i - 1] * i % MOD;
	f[N] = power(F[N], MOD - 2);
	for(int i = N - 1; i >= 0; i --)
		f[i] = f[i + 1] * (i + 1) % MOD;
	for(int i = 1; i <= N; i ++)
		inv[i] = f[i] * F[i - 1] % MOD;
	scanf("%s", S + 1);
	for(int i = 1; i <= N; i ++) {
		scanf("%d", &C[i]);
		ps[C[i]] ++, pt[C[i]] ++;
	}
	for(int i = N - 1; i >= 0; i --)
		ps[i] += ps[i + 1];
	for(int i = 1; i <= N; i ++)
		pt[i] += pt[i - 1];
	sort(C + 1, C + N + 1);
	for(int i = 1; i <= N; i ++)
		if(S[i] == '1')
			p1[cnt ++] = i;
	ll wt = 1;
	for(int i = 0; i < cnt; i ++) {
		(ans += wt * ps[p1[i]] % MOD * F[N - i - 1] % MOD) %= MOD;
		wt = wt * (pt[p1[i] - 1] - i) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
