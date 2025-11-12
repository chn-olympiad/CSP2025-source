#include <iostream>
#include <cstdio>
#include <vector>
#define get_Hash(l, r) ((Hah[r] - Hah[l - 1] * bas[r - (l) + 1] % mod + mod) % mod)
#define get_hash(l, r) ((hah[r] - hah[l - 1] * bas[r - (l) + 1] % mod + mod) % mod)
#define get_h1(l, r) ((h1[r] - h1[l - 1] * bas[r - (l) + 1] % mod + mod) % mod)
#define get_h2(l, r) ((h2[r] - h2[l - 1] * bas[r - (l) + 1] % mod + mod) % mod)
using namespace std;
const int N = 2e5 + 7, M = 1e6 + 7;
const int mod = 1e9 + 7, base = 131;
typedef long long ll;
typedef pair <int, int> pll;
int n, m;
int len[N], mx;
ll p[N], q[N], v[30];
ll Hah[M], hah[M], bas[M];
ll h1[M], h2[M];
string s1[N], s2[N];
vector <int> g[N];
vector <pll> h[N];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if(n <= 2000 && m <= 2000){
	bas[0] = 1;
	for(int i = 1; i <= n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		len[i] = s1.length();
		for(auto u : s1) p[i] = (p[i] * base + u - 'a' + 1) % mod;
		for(auto u : s2) q[i] = (q[i] * base + u - 'a' + 1) % mod;
		while(mx < len[i]) mx++, bas[mx] = bas[mx - 1] * base % mod;
	}
	while(m--){
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.length() != t2.length()){cout << "0\n"; continue; }
		int l = t1.length(), r = t2.length();
		while(mx < l) mx++, bas[mx] = bas[mx - 1] * base % mod;
		t1 = " " + t1, t2 = " " + t2;
		for(int i = 1; i <= l; i++) Hah[i] = (Hah[i - 1] * base + t1[i] - 'a' + 1) % mod;
		for(int i = 1; i <= r; i++) hah[i] = (hah[i - 1] * base + t2[i] - 'a' + 1) % mod;
		ll cnt = 0;
		for(int i = 1; i <= l; i++){
			for(int j = 1; j <= n; j++){
				if(i + len[j] - 1 > l) continue;
				if(p[j] != get_Hash(i, i + len[j] - 1)) continue;
				if(q[j] != get_hash(i, i + len[j] - 1)) continue;
				if(get_hash(i + len[j], l) != get_Hash(i + len[j], r)) continue;
				cnt++;
			}
			if(t1[i] != t2[i]) break;
		}
		cout << cnt << "\n";
	}
	}else{
		for(int i = 1; i <= n; i++){
			string s1, s2;
			cin >> s1[i] >> s2[i];
		}
		int p1 = 0, p2 = n, l = 0, r = 0;
		ll cnt = 0;
		while(m--){
			string t1, t2;
			cin >> t1 >> t2;
			if(t1.length() != t2.length()){cout << "0\n"; return 0; }
			l = t1.length(), r = t2.length();
			p2 = l + 1;
		while(mx < l) mx++, bas[mx] = bas[mx - 1] * base % mod;
		t1 = " " + t1, t2 = " " + t2;
		for(int i = 1; i <= l; i++) Hah[i] = (Hah[i - 1] * base + t1[i] - 'a' + 1) % mod;
		for(int i = 1; i <= r; i++) hah[i] = (hah[i - 1] * base + t2[i] - 'a' + 1) % mod;
			while(t1[p1 + 1] == t2[p1 + 1]) p1++;
			while(t2[p2 - 1] == t2[p2 - 1]) p2--;
		}
		for(int i = 1; i <= n; i++){
			int len = s1[i].length();
			while(mx < len) mx++, bas[mx] = bas[mx - 1] * base % mod;
			string t1 = " " + s1[i], t2 = " " + s2[i];
			for(int i = 1; i <= len; i++) h1[i] = (h1[i - 1] * base + t1[i] - 'a' + 1) % mod;
			for(int i = 1; i <= len; i++) h2[i] = (h2[i - 1] * base + t2[i] - 'a' + 1) % mod;
			for(int i = 1; i <= len; i++){
				if(i + p2 - p1 > len) break;
				if(i < p1) continue;
				if(p1 && get_Hash(1, p1 - 1) != get_h1(i - p1 + 1, i - 1)) continue;
				if(i + p2 - p1 + 1 <= len && get_Hash(p2 + 1, l) != get_h1(i + p2 - p1 + 1, len)) continue;
				if(get_h2(i, i + p2 - p1) != get_hash(p1, p2)) continue;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
