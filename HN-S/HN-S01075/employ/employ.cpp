#include<bits/stdc++.h>
using namespace std;
const int N = 505 , MOD = 998244353;
int n , m , p[N] , a[N] , cnt;
bool vis[N] , flag;
char s[N];
void dfs(int x){
	if(x > n){
		int ans = 0 , lst = 0;
		for(int i = 1;i <= n;i++){
			if(lst >= a[p[i]]){
				lst++;
				continue;
			}
			if(s[i] == '0')lst++;
			else ans++;
		}
		if(ans >= m)cnt = (cnt + 1) % MOD;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i])continue;
		p[x] = i;
		vis[i] = true;
		dfs(x + 1);
		vis[i] = false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
		if(s[i] != '1')flag = true;
	}
	for(int i = 1;i <= n;i++)cin >> a[i];
	if(!flag){
		if(!m)cout << n;
		else cout << 0;
		return 0;
	}
	dfs(1);
	cout << cnt;
	return 0;
}
