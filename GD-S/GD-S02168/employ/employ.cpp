#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+9;
const int MOD=998244353;
int n,m;
bool s[N];
int c[N];
bool visited[N];
int ans;
// 剩余录用人数=总人数-拒绝人数
void dfs(int day,int rejected) {
	if((n-rejected)<m) {
		return;
	}
	if(day>n) {
		if((n-rejected) >=m) {
			ans = (ans+1) % MOD;
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(visited[i]) {
			continue;
		}
		visited[i] = true;
		const int patient = c[i];
		if(rejected >= c[i] || s[day] == 0) {
			dfs(day+1,rejected+1);
		} else {
			dfs(day+1,rejected);
		}
		visited[i] = false;
	}

}
signed main() {
	// 记得取消注释!!!!!!
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("employ2.in","r",stdin);
	cin>>n>>m;
	string ss;
	cin>>ss;
	for(int i=0; i<ss.size(); i++) {
		if(ss[i] == '1') {
			s[i+1] = true;
		} else {
			s[i+1] =false;
		}
	}
	for(int i=1; i<=n; i++) {
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
