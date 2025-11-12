#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;

const int N = 5e6 + 5, B = 13331;
const int inf = 0x3f3f3f3f;
const ll mod1 = 998244353, mod2 = 1e9 + 9;

int n, q;
ll pw1[N], pw2[N], has1[N][2], has2[N][2], has3[N][2], has4[N][2];
struct node{
	ll l, vl, r, vr, id;
};
unordered_map<ll, int> mp;
map<pii, vector<node>> mp1, mp2;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i <= n; i++) pw1[i] = pw1[i - 1] * B % mod1, pw2[i] = pw2[i - 1] * B % mod2;
	for (int i = 1; i <= n; i++){
		string s, t; cin >> s >> t;
		int n = s.size(); s = ' ' + s, t = ' ' + t;
		int l = 1, r = n;
		while (l <= n && s[l] == t[l]) l++;
		while (r >= 1 && s[r] == t[r]) r--;
		for (int j = 1; j <= n; j++) has1[j][0] = (has1[j - 1][0] * B + (s[j] - 'a' + 1)) % mod1, has1[j][1] = (has1[j - 1][1] * B + (s[j] - 'a' + 1)) % mod2;
		for (int j = 1; j <= n; j++) has2[j][0] = (has2[j - 1][0] * B + (t[j] - 'a' + 1)) % mod1, has2[j][1] = (has2[j - 1][1] * B + (t[j] - 'a' + 1)) % mod2;
		mp1[{(has1[r][0] - has1[l - 1][0] * pw1[r - l + 1] % mod1 + mod1) % mod1, (has2[r][0] - has2[l - 1][0] * pw1[r - l + 1] % mod1 + mod1) % mod1}].push_back({l - 1, has1[l - 1][0], n - r, (has1[n][0] - has1[r][0] * pw1[n - r] % mod1 + mod1) % mod1, i});
		mp2[{(has1[r][1] - has1[l - 1][1] * pw2[r - l + 1] % mod2 + mod2) % mod2, (has2[r][1] - has2[l - 1][1] * pw2[r - l + 1] % mod2 + mod2) % mod2}].push_back({l - 1, has1[l - 1][1], n - r, (has1[n][1] - has1[r][1] * pw2[n - r] % mod2 + mod2) % mod2, i});	
	}
	while (q--){
		string s, t; cin >> s >> t;
		if (s.size() != t.size()) {cout << "0\n"; continue;}
		int n = s.size(); s = ' ' + s, t = ' ' + t;
		int l = 1, r = n;
		while (l <= n && s[l] == t[l]) l++;
		while (r >= 1 && s[r] == t[r]) r--;
		for (int j = 1; j <= n; j++) has3[j][0] = (has3[j - 1][0] * B + (s[j] - 'a' + 1)) % mod1, has3[j][1] = (has3[j - 1][1] * B + (s[j] - 'a' + 1)) % mod2;
		for (int j = 1; j <= n; j++) has4[j][0] = (has4[j - 1][0] * B + (t[j] - 'a' + 1)) % mod1, has4[j][1] = (has4[j - 1][1] * B + (t[j] - 'a' + 1)) % mod2;
		int tmp1 = (has3[r][0] - has3[l - 1][0] * pw1[r - l + 1] % mod1 + mod1) % mod1, des1 = ((has4[r][0] - has4[l - 1][0] * pw1[r - l + 1] % mod1) + mod1) % mod1;
		int tmp2 = (has3[r][1] - has3[l - 1][1] * pw2[r - l + 1] % mod2 + mod2) % mod2, des2 = ((has4[r][1] - has4[l - 1][1] * pw2[r - l + 1] % mod2) + mod2) % mod2;
		int ans = 0;
		mp.clear();
		for (auto it : mp1[{tmp1, des1}]){
			if (it.l > l - 1 || it.r > n - r) continue;
			if ((has3[l - 1][0] - has3[l - it.l - 1][0] * pw1[it.l] % mod1 + mod1) % mod1 == it.vl && (has3[r + it.r][0] - has3[r][0] * pw1[it.r] % mod1 + mod1) % mod1 == it.vr) mp[it.id]++;
		}
		for (auto it : mp2[{tmp2, des2}]){
			if (it.l > l - 1 || it.r > n - r) continue;
			if ((has3[l - 1][1] - has3[l - it.l - 1][1] * pw2[it.l] % mod2 + mod2) % mod2 == it.vl && (has3[r + it.r][1] - has3[r][1] * pw2[it.r] % mod2 + mod2) % mod2 == it.vr) mp[it.id]++;
		}
		for (auto it : mp) ans += (it.sec == 2);
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
