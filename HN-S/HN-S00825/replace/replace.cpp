#include<bits/stdc++.h>
#define int unsigned long long
#define mod 998244353
#define base 13331
using namespace std;
int n, m, ans, len[200005], hs_s[2005][2005], hs_t[2005][2005], bs_s[2005][2005], bs_t[2005][2005];
string s[200005], t[200005], p, q;
void Hash(string s, int arr[], int brr[]){
	brr[0] = 1;
	for(int i = 1; i < s.size(); i++){
		brr[i] = brr[i - 1] * base;
		arr[i] = arr[i - 1] * base + s[i] - 'a';
	}
}
int get_hs(int l, int r, int arr[], int brr[]){
	if(l > r){
		return 0;
	}
	return arr[r] - arr[l - 1] * brr[r - l + 1];
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> t[i];
		len[i] = s[i].size(), s[i] = ' ' + s[i], t[i] = ' ' + t[i];
		Hash(s[i], hs_s[i], bs_s[i]);
		Hash(t[i], hs_t[i], bs_t[i]);
	}
	while(m--){
		cin >> p >> q;
		len[0] = p.size(), p = ' ' + p, q = ' ' + q, ans = 0;
		Hash(p, hs_s[0], bs_s[0]);
		Hash(q, hs_t[0], bs_t[0]);
		for(int i = 1; i <= n; i++){
			int l1 = len[i], l2 = len[0];
			for(int j = 1; j + l1 - 1 <= l2; j++){
				int l = j, r = j + l1 - 1;
				if(get_hs(1, l - 1, hs_s[0], bs_s[0]) == get_hs(1, l - 1, hs_t[0], bs_t[0]) && get_hs(1, l1, hs_t[i], bs_t[i]) == get_hs(l, r, hs_t[0], bs_t[0]) && get_hs(1, l1, hs_s[i], bs_s[i]) == get_hs(l, r, hs_s[0], bs_s[0]) && get_hs(r + 1, l2, hs_s[0], bs_s[0]) == get_hs(r + 1, l2, hs_t[0], bs_t[0])){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

