#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,ans,maxm,mm;
int a[N],maxn[N][N];
void dfs(int x,int m,int s) {
	if(m>=2&&m<=n-1) {
		if(s>mm)s=mm+1;
		ans=(ans+maxn[x+1][s])%998244353;
	}
	for(int i=x+1; i<=n; i++) {
		dfs(i,m+1,s+a[i]);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i],mm=max(mm,a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++)maxn[j][a[i]+1]++;
	}
	for(int i=1; i<=mm+1; i++) {
		for(int j=1; j<=n; j++)maxn[j][i]+=maxn[j][i-1];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
