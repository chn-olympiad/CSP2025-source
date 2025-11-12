#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define vc vector
#define vci vc<int>
#define psb push_back
using namespace std;
//int tot;
//int nx[520005], sn[520005][26], ans[520005];
//vci g[520005];
//struct AC_Machine{
//	int rt;
//	void ins(string s){
//		int nw = rt;
//		for(int i = 0; i < s.size(); i++){
//			int c = (int)(s[i] - 'a');
//			if(!sn[nw][c]) sn[nw][c] = ++tot;
//			nw = sn[nw][c];
//		}
//		ans[nw]++;
//	}
//	void dfs(int u){
//		for(int v : g[u]){
//			ans[v] += ans[u];
//			dfs(v);
//		}
//	}
//	void bld(){
//		queue<int> q;
//		nx[rt] = rt;
//		for(int i = 0; i < 26; i++)
//			if(sn[rt][i]) q.push(sn[rt][i]);
//			else sn[rt][i] = rt;
//		while(q.size()){
//			int u = q.front();
//			q.pop();
//			g[nx[u]].psb(u);
//			for(int i = 0; i < 26; i++)
//				if(!sn[u][i]) sn[u][i] = sn[nx[u]][i];
//				else{
//					nx[sn[u][i]] = sn[nx[u]][i];
//					q.push(sn[u][i]);
//				}
//		}
//		dfs(rt);
//	}
//	ll mch(string s, int r){
//		ll res = 0;
//		int nw = rt;
//		for(int i = 0; i < s.size(); i++){
//			int c = (int)(s[i] - 'a');
//			nw = sn[nw][c];
//			res += ans[nw];
//		}
//		return res;
//	}
//} am[200005];
//map<pair<string, string>, int> id;
//int idx;
int n, q;
int l, r;
string s[200005], t[200005];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i] >> t[i];
	while(q--){
		int ans = 0;
		string S, T;
		cin >> S >> T;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j + s[i].size() - 1 < S.size(); j++)
				if(S.substr(j, s[i].size()) == s[i] && S.substr(0, j) + t[i] + S.substr(j + s[i].size(), S.size() - (j + s[i].size())) == T) ans++;
		cout << ans << endl;
	}
//	for(int i = 1; i <= n; i++){
//		cin >> s >> t;
//		s = ' ' + s, t = ' ' + t;
//		l = 0, r = -1;
//		for(int j = 1; j <= s.size(); j++)
//			if(s[j] != t[j]){
//				if(!l) l = j;
//				r = j;
//			}
////		cout << l << ' ' << r << endl;
//		int &ID = id[{s.substr(l, r - l + 1), t.substr(l, r - l + 1)}];
//		if(!ID) ID = ++idx, am[ID].rt = ++tot;
//		am[ID].ins(s);
////		cout << ID << endl;
//	}
//	while(q--){
//		cin >> s >> t;
//		s = ' ' + s, t = ' ' + t;
//		l = 0, r = -1;
//		for(int j = 1; j <= s.size(); j++)
//			if(s[j] != t[j]){
//				if(!l) l = j;
//				r = j;
//			}
////		cout << l << '~' << r << endl;
//		int ID = id[{s.substr(l, r - l + 1), t.substr(l, r - l + 1)}];
//		if(!ID){
//			cout << 0 << endl;
//			continue;
//		}
////		cout << ID << endl;
//		cout << am[ID].mch(s.substr(1, s.size() - 1), r) << endl;
//	}
	return 0;
}
