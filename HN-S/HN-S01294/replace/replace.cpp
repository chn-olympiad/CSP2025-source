#include<bits/stdc++.h>
using namespace std;
const int base = 131;
unsigned hs[5000005],ht[5000005],pw[5000005];
int n,q,cnt[10000005];
map<pair<int,int>,int> mp;
unsigned get_hs_s(int l,int r){return hs[r] - hs[l - 1] * pw[r - l + 1];}
unsigned get_hs_t(int l,int r){return ht[r] - ht[l - 1] * pw[r - l + 1];}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		string s,t;
		cin >> s >> t;
		unsigned hs1 = 0,hs2 = 0;
		for (int i = 0; i < s.size(); i++){
			hs1 = hs1 * base + s[i];
			hs2 = hs2 * base + t[i];
		}
		mp[{hs1,hs2}]++;
	}
	pw[0] = 1;
	for (int i = 1; i <= 5e6; i++) pw[i] = pw[i - 1] * base;
	while (q--){
		string s,t;
		cin >> s >> t;
		if (n <= 1000){
			int ans = 0;
			for (int i = 0; i < s.size(); i++){
				hs[i + 1] = hs[i] * base + s[i];
				ht[i + 1] = ht[i] * base + t[i];
			}
			for (int i = 0; i < s.size(); i++){
				if (get_hs_s(1,i) != get_hs_t(1,i)) break;
				for (int j = s.size() - 1; j >= i; j--){
					if (get_hs_s(j + 2,s.size()) != get_hs_t(j + 2,s.size())) break;
					if (mp.count({get_hs_s(i + 1,j + 1),get_hs_t(i + 1,j + 1)}))
						ans += mp[{get_hs_s(i + 1,j + 1),get_hs_t(i + 1,j + 1)}];
				}
			}
			cout << ans << '\n';
			continue;
		}
		cout << "0\n";
	}
	return 0;
}
