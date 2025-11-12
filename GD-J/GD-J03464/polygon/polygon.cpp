#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ans,n,a[5005],dp[10005][5005],mx=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i],mx=max(mx,a[i]);
	dp[0][0]=1; 
	for(int k=1;k<=n;k++){
		for(int i=sum;i>=0;i--){
			for(int j=0;j<=min(i,mx);j++){
				dp[min(10001,i+a[k])][max(a[k],j)]+=dp[i][j];
				dp[min(10001,i+a[k])][max(a[k],j)]%=mod; 
				if(min(10001,i+a[k])>2*max(a[k],j)&&dp[min(10001,i+a[k])][max(a[k],j)]){
					ans+=dp[i][j]/*,cerr<<i<<' '<<j<<'\n'*/;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
