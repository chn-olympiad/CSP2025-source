/*
csp-s 2025 rp ++
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	string s, ss;
	int w, ww, id1, id2;
}a[200005];
int n, q, Base[1005], p = 998244353, base = 1331, qzh[2][1005];
bool tag = 1;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	Base[0] = 1;
	for(int i = 1; i <= 1000; i ++){
		Base[i] = (Base[i - 1] * base) % p;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i].s >> a[i].ss;
		for(int j = 1; j <= a[i].s.size(); j ++){
			if(a[i].s[j - 1] != 'a' && a[i].s[j - 1] != 'b'){
				tag = 0;
			}
			else if(a[i].s[j - 1] == 'b' && a[i].id1){
				tag = 0;
			}
			else if(a[i].s[j - 1] == 'b'){
				a[i].id1 = j;
			}
			if(a[i].ss[j - 1] != 'a' && a[i].ss[j - 1] != 'b'){
				tag = 0;
			}
			else if(a[i].ss[j - 1] == 'b' && a[i].id2){
				tag = 0;
			}
			else if(a[i].ss[j - 1] == 'b'){
				a[i].id2 = j;
			}
		}
	}
	if(!tag){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= a[i].s.size(); j ++){
				a[i].w += Base[j] * (a[i].s[j - 1] - 'a' + 1);
				a[i].ww += Base[j] * (a[i].ss[j - 1] - 'a' + 1);
				a[i].w %= p;
				a[i].ww %= p;
			}
		}
	}
	while(q --){
		int ans = 0, l = 0, r = 0;
		string t, tt;
		cin >> t >> tt;
		if(tag){
			for(int i = 1; i <= t.size(); i ++){
				if(t[i - 1] == 'b'){
					l = i;
				}
				if(tt[i - 1] == 'b'){
					r = i;
				}
			}
			for(int i = 1; i <= n; i ++){
				if(a[i].id2 - a[i].id1 == r - l && a[i].s.size() - a[i].id1 <= t.size() - l && a[i].id1 >= l){
					ans ++;
				}
			}
			cout << ans << '\n';
			continue;
		}
		for(int i = 1; i <= t.size(); i ++){
			if(t[i - 1] != tt[i - 1]){
				r = i;
				if(!l){
					l = i;
				}
			}
			qzh[0][i] = qzh[0][i - 1] + Base[i] * (t[i - 1] - 'a' + 1);
			qzh[1][i] = qzh[1][i - 1] + Base[i] * (tt[i - 1] - 'a' + 1);
			qzh[0][i] %= p;
			qzh[1][i] %= p;
		}
		for(int i = 1; i <= n; i ++){
			for(int j = a[i].s.size(); j <= t.size(); j ++){
				if(j - a[i].s.size() + 1 <= l && j >= r && (qzh[0][j] - qzh[0][j - (int)a[i].s.size()] + p) % p == a[i].w * Base[j - (int)a[i].s.size()] % p && (qzh[1][j] - qzh[1][j - (int)a[i].s.size()] + p) % p == a[i].ww * Base[j - (int)a[i].s.size()] % p){
					ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
