#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 10, base = 131, MOD = 114137891; 

int n, q, h[N][2], b[N], dp[N * 25];
pair<int, int> pp[N];
map<pair<string, string>, int> mp;
string s, t, p[N][2];

int hash(int l, int r, int id){
	if(r < l){
		return 0;
	}
	return (h[r][id] - h[l - 1][id] * b[r - l + 1] % MOD + MOD) % MOD; 
}

void solve(){
	while(q--){
		cin >> s >> t;
		if(s.size() != t.size()){
			cout << 0 << '\n';
			continue;
		}
		int len = s.size(); b[0] = 1;
		s = ' '  + s, t = ' ' + t; 
		for(int i = 1; i <= len; i++){
			b[i] = b[i - 1] * base % MOD;
			h[i][0] = (h[i - 1][0] * base + s[i]) % MOD;
			h[i][1] = (h[i - 1][1] * base + t[i]) % MOD;
		}	
		int sum = 0;
		for(int i = 1; i <= n; i++){
			int h1 = 0, h2 = 0, l = p[i][0].size();
			for(int j = 0; j < l; j++){
				h1 = (h1 * base + p[i][0][j]) % MOD;
				h2 = (h2 * base + p[i][1][j]) % MOD;
			}
			int fl = 0;
			for(int j = 1; j + l - 1 <= len; j++){
				int k = j + l - 1;
				fl |= (hash(1, j - 1, 0) == hash(1, j - 1, 1) && hash(j, k, 0) == h1 && hash(j, k, 1) == h2 && hash(k + 1, len, 0) == hash(k + 1, len, 1));
			}
			sum += fl;
		}
		cout << sum << '\n';
	}
}

void solve2(){
	map<int, vector<int> > mp;
	for(int i = 1; i <= n; i++){
		int id1 = 0, id2 = 0, len = p[i][0].size(); 
		for(int j = 0; j < p[i][0].size(); j++){
			if(p[i][0][j] == 'b') id1 = j;
			if(p[i][1][j] == 'b') id2 = j;
		}
		pp[i] = {id1, len - id2};
		mp[id1 - id2].push_back(i);
	}
	while(q--){
		cin >> s >> t;
		if(s.size() != t.size()){
			cout << 0 << '\n';
			continue;
		}
		int len = s.size(); b[0] = 1;
		s = ' '  + s, t = ' ' + t; 
		int id1 = 0, id2 = 0, sum = 0;
		for(int j = 1; j <= len; j++){
			if(s[j] == 'b') id1 = j;
			if(t[j] == 'b') id2 = j;
		}
		vector<int> v = mp[id1 - id2];
		for(int i = 0; i < v.size(); i++){
			int j = v[i];
			sum += (id1 - 1 >= pp[j].first && len - id2 + 1 >= pp[j].second);
		}
		cout << sum << '\n';
	}
}

signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q; b[0] = 1;
	int fl = 0;
	for(int i = 1; i <= n; i++){
		cin >> p[i][0] >> p[i][1];
		for(int j = 0; j < p[i][0].size(); j++){
			fl |= p[i][0][j] > 'b' || p[i][1][j] > 'b';
		}
	}
	if(!fl){
		solve2();
		return 0; 
	}
	if(n <= 1e3 && q <= 1e3){
		solve();
		return 0;
	}
	return 0;
}
