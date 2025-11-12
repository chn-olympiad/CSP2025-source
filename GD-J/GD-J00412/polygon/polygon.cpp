#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005],s[5005],dp[505][50005],t[5005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		dp[i][a[i]]=1;
		for(int j=a[i]+1;j<=s[i];j++)dp[i][j]=(dp[i][j]+t[j-a[i]])%Mod;
		for(int j=a[i];j<=s[i];j++)t[j]=(t[j]+dp[i][j])%Mod;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=s[i];j++)cout<<dp[i][j]<<' ';
//		cout<<'\n';
//	}
	int ans=0;
	for(int i=3;i<=n;i++)
		for(int j=2*a[i]+1;j<=s[i];j++)ans=(ans+dp[i][j])%Mod;
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
