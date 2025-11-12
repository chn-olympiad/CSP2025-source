#include <bits/stdc++.h>
using namespace std;
const int N = 5500005;
int n, q, son[N][27], ne[N], rt = 1, cnt = 1, sz[N];
vector <int> g[N];
void ins(string h){
	int x = rt;
	for(char i: h){
		if(!son[x][i - 'a']) g[x].push_back(((i - 'a') << 23) + cnt + 1), son[x][i - 'a'] = ++cnt;
		x = son[x][i - 'a'];
	}
	sz[x]++;
}
void bt(){
	queue <int> q; q.push(1), ne[1] = 1;
	while(q.size()){
		int t = q.front(); q.pop();
		if(t != 1) memcpy(son[t], son[ne[t]], 108);
		else for(int i = 0; i < 27; i++) son[t][i] = 1;
		for(int r: g[t]){
			int i = r >> 23, o = r & ((1 << 23) - 1); son[t][i] = o;
			q.push(o), ne[o] = t == 1? 1: son[ne[t]][i], sz[o] += sz[ne[o]];
		}
	}
}
string trs(string s, string t){
	string h;
	int p = 0, j;
	for(j = s.size() - 1; ~j; j--)
		if(s[j] != t[j]){ p = j; break;}
	for(j = 0; j < s.size(); j++){
		if(s[j] != t[j]) break;
		h += s[j];
	}
	h += '{'; int ls = j;
	for(; j <= p; j++) h += s[j];
	j = ls;
	for(; j <= p; j++) h += t[j];
	h += '{';
	for(; j < s.size(); j++) h += s[j];
	return h;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s, t; cin >> s >> t;
		if(s == t) continue; 
		ins(trs(s, t)); 
	}
	bt();
	for(int o = 1; o <= q; o++){
		string s, t; cin >> s >> t;
		string h = trs(s, t);
		int x = rt, ans = 0;
		for(char i: h) x = son[x][i - 'a'], ans += sz[x];
		cout << ans << '\n';
	}
	return 0;
}
