#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
const unsigned long long B = 131;
int n, q;
unsigned long long a[N], b[N], BB[N];
map <unsigned long long, unsigned long long> mp;
inline unsigned long long zao(string &s) {
	unsigned long long tmp = 0;
	for(int i = 0; i < s.size(); i++) {
		tmp = tmp * B + (int)s[i];
	}
	return tmp;
}
inline bool query(int l, int r) {
	if(l > r) return true;
	unsigned long long ans1 = a[r] - a[l - 1] * BB[r - l + 1];
	unsigned long long ans2 = b[r] - b[l - 1] * BB[r - l + 1];
	return ans1 == ans2;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	string s1, s2;
	for(int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		mp[zao(s1)] = zao(s2);
	}
	/*/cout << "mp:" << endl;
	for(auto it : mp) {
		cout << it.first << " " << it.second << endl;
	}/*/
	string t1, t2;
	for(int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		int len1 = t1.size();
		int len2 = t2.size();
		if(len1 != len2) {
			cout << 0 << "\n";
			continue;
		}
		t1 = " " + t1;
		t2 = " " + t2;
		BB[0] = 1;
		for(int j = 1; j <= len1; j++) {
			a[j] = a[j - 1] * B + (int)t1[j];
			b[j] = b[j - 1] * B + (int)t2[j];
			BB[j] = BB[j - 1] * B;
			//cout << "j:" << j << " a:" << a[j] << " b:" << b[j] << endl;
		}
		int ans = 0;
		for(int l = 1; l <= len1; l++) {
			for(int r = l; r <= len1; r++) {
				unsigned long long tmp = a[r] - a[l - 1] * BB[r - l + 1];
				if(!mp.count(tmp)) continue;
				unsigned long long tmp1 = mp[tmp];
				unsigned long long tmp2 = b[r] - b[l - 1] * BB[r - l + 1];
				//cout << "tmp:" << tmp << " tmp1:" << tmp1 << " tmp2:" << tmp2 << endl; 
				if(tmp1 != tmp2) continue;
				if(!query(1, l - 1) || !query(r + 1, len1)) continue;
				//cout << "l:" << l << " r:" << r << endl;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}