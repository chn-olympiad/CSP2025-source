#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n,m,c[N],p[N],ans;
string s;
bool use[N];
void check(){
	int ct = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] - '0' == 0 || i - 1 - ct >= c[p[i]]) continue;
		++ct;
	}
	if(ct >= m) ++ans;
}
void dfs(int x){
	if(x == n + 1){
		check();
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!use[i]){
			use[i] = 1;
			p[x] = i;
			dfs(x + 1);
			use[i] = 0;
		}
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s; 
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
} 
/*
3 2
101
1 1 2
*/
