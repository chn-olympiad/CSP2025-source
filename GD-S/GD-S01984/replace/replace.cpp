#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int maxn = 1e6 + 5, maxm = 5e6 + 5, mod = 19260817, base = 131;
int n, q;
namespace Sol1{
	int h[maxn], h2[maxn], p[maxm];
	int h3[maxm], h4[maxm], L[maxn], R[maxn], cnt[maxn];
	vector<int> mp[26][26];
	string s[maxn], s2[maxn];
	int add(int x, int y){x += y; if (x >= mod) x -= mod; return x;}
	int sub(int x, int y){x -= y; if (x < 0) x += mod; return x;}
	int get_hash(int l, int r, int h[]){
		return sub(h[r], h[l - 1] * p[r - l + 1] % mod); 
	}
	void solve(){
		p[0] = 1; for (int i = 1; i < maxn; i++) p[i] = p[i - 1] * base % mod;
		for (int i = 1; i <= n; i++){
			string s, s2; cin >> s >> s2;
			for (int j = 0; j < s.size(); j++) h[i] = add(h[i] * base % mod, s[j] - 'a');
			for (int j = 0; j < s2.size(); j++) h2[i] = add(h2[i] * base % mod, s2[j] - 'a');
			L[i] = s[0] - 'a'; R[i] = s2[0] - 'a'; cnt[i] = s.size();
		}while(q--){
			string t, t2; cin >> t >> t2; t = " " + t; t2 = " " + t2; int len = t.size(), st = len, ed = 0;
			for (int i = 1; i < len; i++) {
				h3[i] = add(h3[i - 1] * base % mod, t[i] - 'a');
				h4[i] = add(h4[i - 1] * base % mod, t2[i] - 'a');
			}for (int i = 1; i < len; i++) if (t[i] != t2[i]) {st = i; break;}
			for (int i = len - 1; i >= 1; i--) if (t[i] != t2[i]) {ed = i; break;}
			for (int i = 1; i < len; i++) mp[t[i] - 'a'][t2[i] - 'a'].clear();
			for (int i = 1; i < len; i++) mp[t[i] - 'a'][t2[i] - 'a'].pb(i); int ans = 0;
			for (int i = 1; i <= n; i++){
				for (auto x : mp[L[i]][R[i]]) {
					if (x + cnt[i] - 1 > len - 1 || x > st || x + cnt[i] - 1 < ed) continue;
					if (get_hash(x, x + cnt[i] - 1, h3) == h[i] && get_hash(x, x + cnt[i] - 1, h4) == h2[i]) ans++;
				}
			}cout << ans << '\n';
		} 
	}
}
// namespace Sol2{
	// string s[maxn], s2[maxn];
	// int cnt[maxn], pos[maxn], pos2[maxn];
	// map<int, int> res;
	// void solve(){
		// res.clear();
		// for (int i = 1; i <= n; i++){
			// cin >> s[i] >> s2[i];
			// for (int j = 0; j < s[i].size(); j++){
				// if (s[i][j] == 'b') pos[i] = j; if (s2[i][j] == 'b') pos2[i] = j;
			// }res[pos2[i] - pos[i]]++;
		// }while(q--){
			// string t, t2; cin >> t >> t2;
			// int p1, p2;
			// for (int i = 0; i < t.size(); i++) {
				// if (t[i] == 'b') p1 = i; if (t2[i] == 'b') p2 = i;
			// }cout << res[p2 - p1] << '\n';
		// }
	// }
// }
main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q; Sol1::solve();
	// if (n <= 1000 && q <= 1000) 
	// else Sol2::solve();
}