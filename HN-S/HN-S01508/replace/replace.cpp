#include<bits/stdc++.h>
using namespace std;
int n, m, cnt;
string a, b;
map<pair<string, string>, bool> mp, vis;
void dfs(int x){
	if(x == a.size() - 1){
		cnt ++;
		return;
	}
	string aa, bb;
	for(int i = x + 1; i < b.size(); i ++){
		aa = aa + a[i];
		bb = bb + b[i];
		if(mp[make_pair(aa, bb)] && !vis[make_pair(aa, bb)]){
			vis[make_pair(aa, bb)] = true;
			dfs(i);
			vis[make_pair(aa, bb)] = false;
		}
	}
	return;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		string a, b;
		cin >> a >> b;
		mp[make_pair(a, b)] = true;
	}
	for(int i = 0; i < 26; i ++){
		string a = a + char('a' + i);
		mp[make_pair(a, a)] = true;
	}
	while(m--){
		cnt = 0;
		cin >> a >> b;
		dfs(-1);
		cout << cnt <<"\n";
	}
	return 0;
}
