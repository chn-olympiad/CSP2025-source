#include <bits/stdc++.h>
using namespace std;
int n,a[5050],c[5050][5050];
long long ans,mod=998244353;
void dfs(int k,int m,int cnt,int maxx){
	if(k>n and m>=3 and cnt>maxx*2){
		ans=(ans+1)%mod;
		return;
	}else if(k>n) return;
	dfs(k+1,m,cnt,maxx);
	maxx=max(a[k],maxx);
	cnt=cnt+a[k]; m=m+1;
	dfs(k+1,m,cnt,maxx);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20){
		dfs(1,0,0,0);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++)
			c[i][i]=1;
		for(int i=1;i<=n;i++)
			c[i][1]=i;
		for(int i=1;i<=n;i++)
			for(int j=2;j<i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				c[i][j]=c[i][j]%mod;
			}
		for(int i=(int)ceil((double)n/2.0);i<=n;i++)
			ans=(ans+c[n][i])%mod;
		cout<<ans%mod;
	}
	return 0;
}
