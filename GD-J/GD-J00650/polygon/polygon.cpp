//sum > max*2  ==  sum-max > max 
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
const int INF=0x3f3f3f3f, M=5005, MOD=998244353;
int n, m, ans;
int a[M], b[M];
void check(){
	int sum=0, maxx=0, cnt=0;
	for (int i=1; i<=n; i++){
		if (b[i]){
			cnt++;
			sum+=a[i];
			maxx=max(maxx, a[i]);
		} 
	}
	if (sum > maxx*2 && cnt >= 3) ans++;
	return ;
}
void dfs(int x){
	if (x > n){
		check();
		return ;
	}
	for (int i=0; i<=1; i++){
		b[x]=i;
		dfs(x+1);
	}
	return ;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i], m=max(m, a[i]);
	if (m == 1){
		ans=1;
		for (int i=1; i<=n; i++) ans*=2, ans%=MOD;
		ans-=(n+n*(n-1)/2); ans+=MOD; ans%=MOD;
		cout << ans-1;
	} 
	else {
		dfs(1);
		cout << ans;
	}
	
	return 0;
}
 
