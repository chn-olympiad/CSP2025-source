#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node{
	string x, y;
}a[200005];
long long ans;
bool vis[200005];
bool check(string &s, int x) {
	for(int i = 0; i < s.size() - a[x].x.size() + 1; i++) {
		string tmp = "";
		for(int j = i; j < i + a[x].x.size(); j++) {
			tmp = tmp + s[j];
		}
		if(tmp == a[x].x) {
			for(int j = i; j < i + a[x].x.size(); j++) {
				s[j] = a[x].y[j - i];
			}
			return 1;
		}
	}
}
void dfs(int x, string s, string ex) {
//	cout << x << ' ' << s << ' ' << ex << endl;
	if(s == ex) {
		ans++;
		return ;
	}
	if(x == 2) {
		return ;
	}
	for(int i = 1; i <= n; i++) {
		string tmp = s;
		if(!vis[i] && check(s, i)) {
			vis[i] = 1;
			dfs(x + 1, s, ex);
			s = tmp;
			vis[i] = 0;
		}
//		cout << s << endl;
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	for(int i = 1; i <= m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		memset(vis, 0, sizeof vis); 
		ans = 0;
		dfs(1, s1, s2);
		printf("%d\n", ans);
	}
	return 0;
}
