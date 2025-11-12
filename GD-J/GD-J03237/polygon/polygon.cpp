#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=1e4+5;
int n,b[5005],c[5005],ans,a[5005],dp[5005][N],dp1[5005][N];
bool flag=true;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]!=1)flag=false;
	}
	for(int i=3;i<=n;i++){
		a[1]=1;
		for(int i=2;i<=n;i++)a[i]=a[i-1]*i;
		long long num=1;
		for(int j=n;j>=n+1-i;j--)num=(num*j)%mod;
		a[i]=(num/a[i])%mod;
	}
	if(flag){
		for(int i=3;i<=n;i++)ans=(ans+a[i])%mod;
		printf("%lld\n",ans);
		return 0;
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+b[i];
	if(c[3]>b[3]*2)dp[3][b[3]*2]=1;
	for(int i=4;i<=n;i++){
		for(int j=N;j>=1;j--){
			for(int k=1;k<i;k++){
				if(c[i]-b[k]>j && dp1[i][c[i]-k]>3){
					if(dp[i][c[i]-b[k]]+1>dp[i][j]){
						dp[i][j]=dp[i][c[i]-k]+1;
						dp1[i][j]=dp1[i][c[i]-k]-1;
					}
				}else break;
				
			}
		}
		ans=(ans+dp[i][i*2])%mod;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
