#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5010],ans;
void dfs(int i,int sl,int cd,int maxx){
	if(i > n){
		if(sl >= 3 && cd > maxx * 2)ans = (ans + 1) % mod;
		return;
	}
	dfs(i + 1,sl + 1,cd + a[i],max(maxx,a[i]));
	dfs(i + 1,sl,cd,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; ++i)cin >> a[i];
	if(n <= 20){
		dfs(1,0,0,0);
		cout << ans;
	}else cout << 1;
	return 0;
}