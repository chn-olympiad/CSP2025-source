#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],ans,flag,c[5005][5005];
const ll N = 998244353;
void dfs(int x,ll sum){
	if(x==n+1) return ; 
	dfs(x+1,sum);
	if(a[x]<sum) ans=(ans+1)%N;
	dfs(x+1,sum+a[x]); 
}
void init(){
	c[1][1] = 1;
	for(int i=2;i<=n;i++){
		c[i][1] = i,c[i][i] = 1;
		for(int j=2;j<i;j++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1])%N;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) flag = 1;
	}
	if(!flag){
		init();
		for(int i=3;i<=n;i++)
			ans += c[n][i];
		cout << ans;
		return 0;
	}
	sort(a+1,a+1+n);
	dfs(1,0);
	cout << ans;
	return 0;
}
