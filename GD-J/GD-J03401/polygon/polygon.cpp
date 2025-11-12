#include<bits/stdc++.h>
using namespace std;
int n,ans,tot,a[5005];
void dfs(int step,int maxn,int sum){
	if(step > n){
		if(sum > 2 * maxn) ans = (ans + 1) % 998244353;
		return;
	}
	dfs(step + 1,maxn,sum);
	dfs(step + 1,max(maxn,a[step]),sum + a[step]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i];
		tot += a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = n;i >= 1;--i){
		if(tot <= i * 2) n--;
		else break;
	}
	dfs(1,0,0);
	cout << ans << "\n";
	return 0;
} 
