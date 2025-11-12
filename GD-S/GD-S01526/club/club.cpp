#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5+5;
int t;
int a[maxn], b[maxn], c[maxn];
struct Student{
	int val, id;
	operator < (const Student & o) const {
		return val > o.val;
	}
}s[maxn*2];
vector<int> aa, ab, ac;
bool vis[maxn];
int cnta, cntb, cntc;
int ans;

signed main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] > b[i]) {
				if (a[i] > c[i]) {
					cnta++;
					aa.push_back(i);
					ans += a[i];
				} else {
					cntc++;
					ac.push_back(i);
					ans += c[i];
				}
			} else {
				if (b[i] > c[i]) {
					cntb++;
					ab.push_back(i);
					ans += b[i];
				} else {
					cntc++;
					ac.push_back(i);
					ans += c[i];
				}
			}
		}
		int cnt = 0;
		if (cnta > n/2) {
			for (int i:aa) {
				s[++cnt].val = b[i]-a[i];
				s[cnt].id = i;
				s[++cnt].val = c[i]-a[i];
				s[cnt].id = i;
			}
			sort(s+1, s+1+cnt);
			for (int i=1; i<=cnt; i++) {
				if (cnta <= n/2) break;
				if (vis[s[i].id]) continue;
				ans += s[i].val;
				vis[s[i].id] = 1;
				cnta--;
			}
		}
		else if (cntb > n/2) {
			for (int i:ab) {
				s[++cnt].val = a[i]-b[i];
				s[cnt].id = i;
				s[++cnt].val = c[i]-b[i];
				s[cnt].id = i;
			}
			sort(s+1, s+1+cnt);
			for (int i=1; i<=cnt; i++) {
				if (cntb <= n/2) break;
				if (vis[s[i].id]) continue;
				ans += s[i].val;
				vis[s[i].id] = 1;
				cntb--;
			}
		}
		else if (cntc > n/2) {
			for (int i:ac) {
				s[++cnt].val = a[i]-c[i];
				s[cnt].id = i;
				s[++cnt].val = b[i]-c[i];
				s[cnt].id = i;
			}
			sort(s+1, s+1+cnt);
			for (int i=1; i<=cnt; i++) {
				if (cntc <= n/2) break;
				if (vis[s[i].id]) continue;
				ans += s[i].val;
				vis[s[i].id] = 1;
				cntc--;
			}
		}
		cout << ans << '\n';
		cnta = cntb = cntc = ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(s, 0, sizeof(s));
		aa.clear();
		ab.clear();
		ac.clear();
	}
} 
