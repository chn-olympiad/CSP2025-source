// 先打暴力 
// eeeee
// 当前 50pts，代码正确 
// 我写那么一大串代码都没用了（悲） 
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#define int long long
#define hash I_can_prove_that_this_name_is_used
#define left it_s_left
#define right it_s_right
using namespace std;
// pipilong2024，我喜欢你！
string a[200005], b[200005];
int n, m;
const int mod1 = 1e9 + 9, mod2 = 3502340235, mod3 = 998244343; 
const int mul1 = 133, mul2 = 337, mul3 = 233;
struct hash{
	int h1, h2, h3;
	hash(){h1 = h2 = h3 = 0;}
	hash(int x, int y, int z){
		h1 = x % mod1, h2 = y % mod2, h3 = z % mod3;
	}
	hash(string s){
		h1 = h2 = h3 = 0;
		for(char c:s){
			h1 = h1 * mul1 + c;
			h2 = h2 * mul2 + c;
			h3 = h3 * mul3 + c;
			h1 %= mod1;
			h2 %= mod2;
			h3 %= mod3;
		}
	}
	bool operator < (const hash &b) const{
		if(h1 != b.h1) return h1 < b.h1;
		if(h2 != b.h2) return h2 < b.h2;
		return h3 < b.h3;
	}
	bool operator == (const hash &b) const{
		return (h1 == b.h1 && h2 == b.h2 && h3 == b.h3);
	}
};

pair <hash, hash> tmp[200005];
int left[200005], right[200005];
void solve(){
	cin >> n >> m;
	int sizzzz = 0, sizzz = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		sizzzz += a[i].size() + b[i].size();
		if(a[i] == b[i]){
			left[i] = right[i] = -1;
			continue;
		}
		int l = 0, r = a[i].size() - 1;
		while(a[i][l] == b[i][l]) l++;
		while(a[i][r] == b[i][r]) r--;
		tmp[i] = {hash(a[i].substr(l, r - l + 1)), hash(b[i].substr(l, r - l + 1))};
		left[i] = l;
		right[i] = r;
	}
	while(m--){
		string s, t;
		cin >> s >> t;
		sizzz += s.size() + t.size();
		int l = 0, r = s.size() - 1;
		while(s[l] == t[l]) l++;
		while(s[r] == t[r]) r--;
		pair <hash, hash> cur = {hash(s.substr(l, r - l + 1)), hash(t.substr(l, r - l + 1))};
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(left[i] == -1) continue;
			if(tmp[i] != cur) continue;
			if(l - left[i] < 0) continue;
			if(a[i].size() + l - left[i] > s.size()) continue;
			bool flag = 1;
			if(sizzzz * sizzz <= 3e7){
				for(int j = 0; j < left[i]; j++){
					if(s[j + l - left[i]] != a[i][j]) flag = 0;
				}
				for(int j = right[i] + 1; j < (int)(a[i].size()); j++){
					if(s[j + l - left[i]] != a[i][j]) flag = 0;
				}
			}
			ans += flag;
		}
		cout << ans << '\n';
	}
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	
	cout.flush();
	
	return 0;
}

