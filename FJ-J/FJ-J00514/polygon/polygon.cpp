#include <bits/stdc++.h>
using namespace std;
int n,sum,ans,a[5200],dp[5200][5200];
void dfs(int x,int maxn,int cen){
	if(sum>maxn*2 && cen>=3){
		ans=(ans+1)%998244353;
	}
	for(int i=x+1;i<=n;i++){
		sum+=a[i];
		dfs(i,max(maxn,a[i]),cen+1);
		sum-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3){
		cout<<"0"<<endl;
		return 0;
	}
	if(n==3){
		int sum=a[0]+a[1]+a[2];
		if(sum>2*a[0] && sum>2*a[1] && sum>=2*a[2])
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			sum+=a[i];
			dfs(i,a[i],1);
			sum-=a[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			dp[i][1]=i;
			for(int j=2;j<=n;j++)
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%998244353;
		}
		for(int i=3;i<=n;i++)
			ans=(ans+dp[n][i])%998244353;
		cout<<ans<<endl;
	}
	return 0;
}
