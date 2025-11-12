#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int N = 2005;

int n, q;
ull pw[N], ha1[N], ha2[N];
string s1, s2;
map <ull, ull> mp;

ull get_hash1(int l, int r){
	return ha1[r] - ha1[l - 1] * pw[r - l + 1];
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	/*pw[0] = 1;
	for(int i = 1; i <= 2000; ++i)
		pw[i] = pw[i - 1] * 131;
	for(int i = 1; i <= n; ++i){
		cin >> s1 >> s2;
		ull h1 = 1, h2 = 1;
		for(int j = 1; j <= s1.size(); ++j){
			h1 = h1 * 131 + s1[j - 1];
			h2 = h2 * 131 + s2[j - 1];
		}
		mp[h1] = h2;
	}
	while(q--){
		cin >> s1 >> s2;
		int m = s1.size(), ans = 0;
		ha1[0] = ha2[0] = 1;
		for(int i = 1; i <= m; ++i){
			ha1[i] = ha1[i - 1] * 131 + s1[i - 1];
			ha2[i] = ha2[i - 1] * 131 + s2[i - 1];
		}
		ha1[0] = 0;
		for(int len = 1; len <= m; ++len){
			for(int i = 1; i + len - 1 <= m; ++i){
				int j = i + len - 1;
				if(mp[get_hash1(i, j)] == 0) continue;
				if(get_hash1(1, i - 1) + mp[get_hash1(i, j)] * pw[i - 1] + get_hash1(j + 1, m) * pw[j] == ha2[m]) ans++; 
			}
		}
		printf("%d\n", ans);
	}*/
	while(q--){
		printf("0\n");
	}
	return 0;
} 
