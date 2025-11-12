#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 510;
const int mod = 998244353;
int n,m;
string s;
int a[maxn];
int c[maxn];
int lst[maxn];
int vis[maxn];
ll ans;
void dfs(int nw){
	if(nw == n+1){
		int f = 0;
		int p = 0;
		for(int i = 1; i <= n; i++){
			int idx = lst[i];
			if(f >= c[idx]){
				f++;
				continue;
			}
			if(a[i] == 0){
				f++;
				continue;
			}
			p++;
		}
		if(p >= m){
			ans = (ans+1)%mod;
		}
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		lst[nw] = i;
		dfs(nw+1);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >>n >> m;
	cin >>s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') a[i+1] = 0;
		else a[i+1] = 1;
	}
	dfs(1);
	cout <<ans <<endl;
	return 0;
} 
