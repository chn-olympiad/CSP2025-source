#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],ans;
long long sum[5005][5005],num;
void dfs(int i,int sum,int maxx){
	if(i>n){
		if(sum>maxx*2) ans++;
		return;
	}
	dfs(i+1,sum+a[i],a[i]);
	dfs(i+1,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		sum[0][0]=1;
		for(int i=1;i<=n;++i){
			sum[i][0]=1;
			for(int j=1;j<=i;++j) sum[i][j]=(sum[i-1][j]+sum[i-1][j-1])%MOD;
		}
		for(int i=3;i<=n;++i) num=(num+sum[n][i])%MOD;
		cout<<num,exit(0);
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
