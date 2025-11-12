#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const int mod = 998244353;
int a[N];
int n;
int ans;
void dfs(int dep,int sum,int maxx){
	if(dep == n + 1){
		if(sum > maxx * 2){
			ans = (ans + 1) % mod;
		}
	}else{
		dfs(dep + 1,sum + a[dep],max(maxx,a[dep]));
		dfs(dep + 1,sum,maxx);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 20){
		dfs(1,0,0);
		cout << ans;
		return 0;
	}else{
		int cnt = 0;
		__int128 l = n,now;
		for(int i = 2;i <= n;i++){
			now = (l * (n - i + 1) / i) % mod;
			if(i >= 3){
				cnt += now; 
			}
			l = now;
		}
		cout << cnt;
	}
	return 0;
}
