#include<iostream>
#define ll long long
using namespace std;
const ll N = 2e5 + 1;
ll n, q;
string s1[N], s2[N];
string t1[N], t2[N];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; ++ i) cin >> s1[i] >> s2[i];
	for(int i = 1; i <= q; ++ i) cin >> t1[i] >> t2[i];
	for(int i = 1; i <= q; ++ i) {
		if(t1[i].size() != t2[i].size()) {
			cout << "0\n";
			continue;
		}
		ll ans = 0;
		string tt1, tt2;
		for(int j = 1; j <= n; ++ j) {
			tt1 = "", tt2 = "";
			int siz = s1[j].size();
			for(int k = 0; k < siz; ++ k) tt1 += t1[i][k], tt2 += t2[i][k];
			if(tt1 == s1[j] && tt2 == s2[j]) {
				string t_t1 = t1[i], t_t2 = t2[i];
				for(int z = 0; z <= siz - 1; ++ z) t_t1[z] = tt2[z];
				if(t_t1 == t_t2) ++ ans;
			}
			for(int k = siz; k < t1[i].size(); ++ k) {
				tt1.erase(0, 1), tt1 += t1[i][k];
				tt2.erase(0, 1), tt2 += t2[i][k];
				if(tt1 == s1[j] && tt2 == s2[j]) {
					string t_t1 = t1[i], t_t2 = t2[i];
					for(int z = k - 1; z <= k + siz - 2; ++ z) t_t1[z] = tt2[z - k + 1];
					if(t_t1 == t_t2) ++ ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
