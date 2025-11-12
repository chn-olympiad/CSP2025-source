#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
vector<int> path;
bool vis[N];
string st;
int ar[N], ans = 0;
void dfs(int k, int cnt, int cntx){//推出人数 
	if(k > n){
		if(cntx >= m) ans++;
		return;
	}
	if(cntx >= m){
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		path.push_back(i);
		if(cnt >= ar[i] || st[k - 1] == '0'){
			dfs(k + 1, cnt + 1, cntx);
		}else{
			dfs(k + 1, cnt, cntx + 1);
		}
		path.pop_back();
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> st;
	for(int i = 1; i <= n; i++) cin >> ar[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
