#include <iostream>
using namespace std;

const int Maxn=5e3+5;
const int MOD=998244353;
int n;int a[Maxn];
int c[Maxn][Maxn];
int ans=0;

void dfs(int x,int sum,int mx,int m){
	if (x==n+1){
		if (m>=3 && sum>2*mx) ans=(ans+1)%MOD;
		return;
	} dfs(x+1,sum+a[x],max(mx,a[x]),m+1);
	dfs(x+1,sum,mx,m);
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;int ma=-43;
	for (int i=1;i<=n;++i){
		cin >> a[i];
		ma=max(ma,a[i]);
	} c[0][0]=1;
	if (ma==1){
		for (int i=1;i<=n;++i){
			for (int j=0;j<=i;++j)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
		} for (int i=3;i<=n;++i)
			ans=(ans+c[n][i])%MOD;
	} else dfs(1,0,0,0);
	cout << ans%MOD;
	return 0;
}
