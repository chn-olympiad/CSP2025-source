#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
typedef long long ll;
const int MAXN = 2e5 + 5, MAXL = 5e6 + 5;
string s[MAXN][2];
int lp[MAXL * 2], rp[MAXL * 2];
bool pre[MAXN], suf[MAXN];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	while(q--){
		string pt, qt;
		cin >> pt >> qt;
		if(pt.size() != qt.size()){
			cout << "0\n";
			continue;
		}
		pre[0] = (pt[0] == qt[0]);
		for(int i = 1; i < pt.size(); i++) pre[i] = (pre[i - 1] && (pt[i] == qt[i]));
		suf[pt.size() - 1] = (pt[pt.size() - 1] == qt[qt.size() - 1]);
		for(int i = qt.size() - 2; i >= 0; i--) suf[i] = (suf[i + 1] && (pt[i] == qt[i]));
		string as, bs;
		ll ans = 0;
		for(int ii = 1; ii <= n; ii++){
			as = s[ii][0] + '#' + pt;
			bs = s[ii][1] + '#' + qt;
			for(int i = 1; i < as.size(); i++){
				int k = lp[i - 1];
				while(k > 0 && as[k] != as[i]) k = lp[k - 1];
				if(as[k] == as[i]) k++;
				lp[i] = k;
				k = rp[i - 1];
				while(k > 0 && bs[k] != bs[i]) k = rp[k - 1];
				if(bs[k] == bs[i]) k++;
				rp[i] = k;
				if(lp[i] == s[ii][0].size() && rp[i] == s[ii][0].size()){
					int lft = i - 2 * s[ii][0].size() - 1, rgt = i - s[ii][0].size();
					if((lft < 0 || pre[lft]) && (rgt >= pt.size() || suf[rgt])) ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
