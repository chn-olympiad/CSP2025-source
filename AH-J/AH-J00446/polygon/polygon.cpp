#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5005],m,b[5005],sum,mx,ans;
int maxl;
long long dp[5005][5005];
long long ksm(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;y>>=1;
	}
	return res;
}
long long calc(long long x){
	long long res=ksm(2,x);
	return (res-1-x-(x-1)*x/2)%mod;
}
void dfs(int now){
	if(now==n+1){
		if(sum>(mx<<1)){
			ans++;
		}
		return;
	}
	dfs(now+1);
	b[++m]=a[now];
	sum+=a[now];
	mx=a[now];
	dfs(now+1);
	m--;
	sum-=a[now];
	mx=b[m];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxl=max(maxl,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=20){
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(maxl<=1){
		cout<<calc(n);
		return 0;
	}
	for(int i=1;i<=n-2;i++){
		int v=a[i];
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int j=i+1;j<=n;j++){
			for(int k=v;k>=a[j];k--){
				dp[j][k]=(dp[j][k]+dp[j-1][k-a[j]]+1)%mod;
			}
		}
		long long tmp=0;
		for(int j=0;j<=v;j++){
			tmp+=dp[i-1][j];
		}
		(ans+=(ksm(2,i-1)-tmp))%=mod;
	}
	cout<<ans;
	return 0;
}
