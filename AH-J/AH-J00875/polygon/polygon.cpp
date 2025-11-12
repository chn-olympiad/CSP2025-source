#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans = 0;
void dfs(int t,int h,int ma,int sum){
	ma = max(ma,a[t]);
	sum += a[t];
	if(sum > ma * 2 && h >= 3){
		ans++;
		ans %= 998244353;
	}
	for(int i = t + 1; i <= n;++i){
		dfs(i,h + 1,ma,sum);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n < 3){
		cout << "0";
		return 0;
	}
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	dfs(1,-1,0,0);
	cout << ans;
	return 0;
}
