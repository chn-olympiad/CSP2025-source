#include <bits/stdc++.h>
using namespace std;
#define prt printf
#define pb push_back
//#define _x first
//#define _y second

typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 500 + 7, INF = 0x3f3f3f3f, MOD = 998244353;

void put(ll x, char el = '\n') {
	printf("%lld", x);
	putchar(el);
}

int p[N], a[N];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		scanf("%d", p+i);
		a[i] = i;
	}
	
	if (m == n) {
		for (int i = 1; i <= n; i++) {
			if (p[i] == 0 || s[i-1] == '0') {
				put(0);
				return 0;
			}
		}
		ll ans = 1;
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= MOD;
		}
		put(ans);
		return 0;
	}
	
	int ans = 0;
	do {
		int f = 0, psd = 0;
		for (int i = 1; i <= n; i++) {
//			put(p[a[i]], " \n"[i==n]);
			if (f >= p[a[i]] || !(s[i-1]-'0')) f++;
			else psd++;
		}
		if (psd >= m) ans++; 
	} while(next_permutation(a+1, a+n+1));
	put(ans);
	return 0;
}

