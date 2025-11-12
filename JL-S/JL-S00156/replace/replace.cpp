#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e6 + 10;
const int base = 13331;
const int mod = 1e9 + 7;

int n, q;
char s1[N], s2[N], p1[N], p2[N], len[N];
int ha1[N], ha2[N]; 
map<int, int> mp; 

int p[N];

int Get1(int l, int r) {
	if (l > r) return 0;
	return (ha1[r] - ha1[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

int Get2(int l, int r) {
	if (l > r) return 0;
	return (ha2[r] - ha2[l - 1] * p[r - l + 1] % mod + mod) % mod;
}

bool Check(int l) {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= l; i++) {
		if (s1[i] == 'b') cnt1++;
		if (s2[i] == 'b') cnt2++;
		if (s1[i] != 'a' && s1[i] != 'b') return 0;
		if (s1[i] != 'a' && s1[i] != 'b') return 0;
	}
	return (cnt1 == 1 && cnt2 == 1);
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	p[0] = 1;
	
	for (int i = 1; i <= 5e6; i++) 
		p[i] = p[i - 1] * base % mod;
	for (int i = 1; i <= n; i++) {
		cin >> s1 + 1 >> s2 + 1;
		int h1 = 0, h2 = 0, l = strlen(s1 + 1);
		len[i] = l;
		for (int j = 1; j <= l; j++) {
			h1 = (h1 * base % mod + s1[j]) % mod;
			h2 = (h2 * base % mod + s2[j]) % mod;
			if (s1[j] == 'b') p1[i] = j;
			if (s2[j] == 'b') p2[i] = j;
		}
	//cout << h1 << ' ' << h2 << "\n";	
		mp[h1] = h2;
	}
	
	while (q--) {
		cin >> s1 + 1 >> s2 + 1;int l = strlen(s1 + 1);
		if (Check(l)) {
			int pa, pb;
			for (int j = 1; j <= l; j++) {
				if (s1[j] == 'b') pa = j;
				if (s2[j] == 'b') pb = j;
			}			
			int k = pa - pb, ans = 0;
			for (int i = 1; i <= n; i++) {
				if (p2[i] - p1[i] == k && p1[i] <= pa && len[i] <= l) {
					ans++;
				}
			}
			cout << ans << "\n";
		}
		else {
			for (int i = 1; i <= l; i++)
				ha1[i] = (ha1[i - 1] * base % mod + s1[i]) % mod, 
				ha2[i] = (ha2[i - 1] * base % mod + s2[i]) % mod;
			int now, nw, ans = 0, cnt = 0;
			for (int i = 1; i <= l; i++) {
				if (ha1[i - 1] != ha2[i - 1]) break;
				for (int j = l; j >= i; j--) {
					cnt++;
					if (q * cnt > 2e8) {
						break;
					}
					if (Get1(j + 1, l) != Get2(j + 1, l)) break;
					now = Get1(i, j), nw = mp[now];
					if (!mp[now]) continue;
					//cout << mp[now] << "\n";
					//nw = (ha1[i - 1] * p[l - i + 1] % mod + mp[now] * p[l - j] % mod + Get1(j + 1, l)) % mod;
					//cout << i << ' ' << j << ' ' << nw << "\n";
					if (nw && nw == Get2(i, j)) ans++;
				}
				if (cnt > 1e6) break;
			}
			cout << ans << "\n";			
		}

	}
	return 0;
}
