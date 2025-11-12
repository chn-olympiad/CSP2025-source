#include <bits/stdc++.h>
using namespace std;

const int maxn = 512, mod=998244353;

int n, m;
char s[maxn];
int c[maxn];
int p[maxn];

int employ() {
	int cnt=0, f=0;
	for (int i=1; i<=n; i++) {
		if (s[i]=='1' && f<c[p[i]]) {
			cnt++;
		} else {
			f++;
		}
	}
	return cnt;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	cin >> (s+1);
	for (int i=1; i<=n; i++) {
		p[i] = i;
		cin >> c[i];
	}
	
	int ans = 0;
	do {
//		printf("employ: %d\n", employ()); 
		ans += employ() >= m;
		ans %= mod;
	} while (next_permutation(p+1, p+n+1));
	
	cout << ans;
	
	return 0;
}

