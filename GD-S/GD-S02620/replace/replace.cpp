#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6 + 5,mod = 998244353,bas = 37;

int n,q;
int len[N];
string s1[N],s2[N];
vector<int> nxt[N];
vector<ll> hshq;
ll pre[N],hsht1[N],hsht2[N],hsh3;
void solve(){
	string que1,que2;
	cin >> que1 >> que2;
	hshq.clear();hsh3 = 0;
	int m = que1.size(),cnt = 0;que1 = " " + que1;que2 = " " + que2;hshq.push_back(0);pre[0] = 1;
	for (int i = 1;i <= m;i++){
		hshq.push_back((hshq[i - 1] * bas % mod + que2[i] - 'a') % mod);
		pre[i] = pre[i - 1] * bas % mod;hsh3 = (hsh3 * bas % mod + que1[i] - 'a') % mod;
	}
	for (int t = 1;t <= n;t++){
		for (int i = 1,p = 0;i <= m;i++){
			while (p != 0 && s1[t][p + 1] != que1[i]) p = nxt[t][p];
			p = p + (s1[t][p + 1] == que1[i]);
			if (p == len[t]){
				ll hsh1 = hsht2[t],hsh2 = (hshq[i] - hshq[i - len[t]] * pre[len[t]] % mod + mod) % mod;
				ll hsh4 = (hshq[m] - pre[m - i] * (hsh2 - hsht1[t]) % mod + mod) % mod;
				if (hsh1 == hsh2 && hsh3 == hsh4) cnt++;
				p = nxt[t][p];
			}
		}
	}cout << cnt << "\n";
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
		len[i] = s1[i].size();s1[i] = " " + s1[i];s2[i] = " " + s2[i];
	}
	for (int i = 1;i <= n;i++){
		nxt[i].push_back(0),nxt[i].push_back(0);
		hsht1[i] = s1[i][1] - 'a';hsht2[i] = s2[i][1] - 'a';
		for (int j = 2,p = 0;j <= len[i];j++){
			while (p != 0 && s1[i][p + 1] != s1[i][j]) p = nxt[i][p];
			p = (p + (s1[i][p + 1] == s1[i][j]));nxt[i].push_back(p);
			hsht1[i] = (hsht1[i] * bas % mod + s1[i][j] - 'a') % mod;
			hsht2[i] = (hsht2[i] * bas % mod + s2[i][j] - 'a') % mod;
		}
	}for (int i = 1;i <= q;i++) solve();
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
