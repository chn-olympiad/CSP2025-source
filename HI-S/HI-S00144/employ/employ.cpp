#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, j, k, w) for(int (i) = (j); ((w) > 0) ? ((i) <= (k)) : ((i) >= (k)); (i) += (w))
const int N = 5e5;
int n, m, c[N], ans;
int d[N];
bool vis[N];
string s;
void dfs(int x){
	if(x == n + 1){
		int sum = 0;
		rep(i, 1, n, 1){
			if(c[d[i]] <= i - sum - 1)continue;
			if(s[i] == '1')sum++;
		}
		if(sum >= m)ans++;
	} 
	rep(i, 1, n, 1){
		if(!vis[i]){
			vis[i] = 1;
			d[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	rep(i, 1, n, 1)cin >> c[i];
	dfs(1); 
	cout << ans << "\n";
	return 0;
}

