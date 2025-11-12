#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1333345193;
const int N = 5e6 + 10;

int n, q, maxl;
ll hash3[N], hash4[N], jc[N];
map<pair<int, int>, int> m;
map<pair<string, string>, int> mm;


void Hash(string &s, ll *h){
	int l = s.size();
	for(int j = 0;j < l;j++){
		int o = s[j] - 'a' + 1;
		if(j) h[j] = h[j - 1] * 137 % M;
		h[j] = (h[j] + o) % M;
	}
}

ll Get(ll *h, int i, int j){
	ll o = 0;
	if(i) o = h[i - 1];
	return (h[j] - o * jc[j - i + 1] % M + M) % M;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	if(n <= 50){
		for(int i = 1;i <= n;i++){
			string s, t;
			cin >> s >> t;
			mm[{s, t}]++;
		}
		
		while(q--){
			string s, t;
			cin >> s >> t;
			int l = s.size();
			ll ans = 0;
			for(int len = 1;len <= l;len++){
				for(int i = 0;i < l - len + 1;i++){
					string xs = "", ys = "", zs = "";
					string xt = "", yt = "", zt = "";
					if(i > 0) xs = s.substr(0, i);
					ys = s.substr(i, len);
					if(i + len < l) zs = s.substr(i + len);
					
					if(i > 0) xt = t.substr(0, i);
					yt = t.substr(i, len);
					if(i + len < l) zt = t.substr(i + len);
					
					if(xs != xt || zs != zt) continue;
					ans += mm[{ys, yt}];
				}
			}
			cout << ans << '\n';
		}
	} else {
		for(int i = 1;i <= n;i++){
			string s, t;
			cin >> s >> t;
			int l = s.size();
			ll hash1 = 0, hash2 = 0;
			maxl = max(maxl, l);
			for(int j = 0;j < l;j++){
				int o = s[j] - 'a' + 1;
				hash1 = (hash1 * 137 % M + o) % M;
				o = t[j] - 'a' + 1;
				hash2 = (hash2 * 137 % M + o) % M;
				//cout << hash1 << ' ' << hash2 << '\n';
			}
			//cout << '\n';
			m[{hash1, hash2}]++;
		}
		
		jc[0] = 1;
		for(int i = 1;i <= 210;i++) jc[i] = jc[i - 1] * 137 % M;
		
		while(q--){
			string s, t;
			cin >> s >> t;
			Hash(s, hash3), Hash(t, hash4);
			int l = s.size();
			ll ans = 0;
			for(int len = 1;len <= l;len++){
				for(int i = 0;i < l - len + 1;i++){
					int j = i + len - 1;
					ll xs = 0, ys = 0, zs = 0, xt = 0, yt = 0, zt = 0;
					if(i){
						xs = hash3[i - 1];
						xt = hash4[i - 1];
					}
					
					ys = Get(hash3, i, j);
					yt = Get(hash4, i, j);
					
					if(j < l - 1){
						zs = Get(hash3, j + 1, l - 1);
						zt = Get(hash4, j + 1, l - 1);
					}
					
					//cout << xs << ' ' << ys << ' ' << zs << ' ' << xt << ' ' << yt << ' ' << zt << '\n';
					if(xs != xt || zs != zt) continue;
					ans += m[{ys, yt}];
				}
			}
			cout << ans << '\n';
		}
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
*/

