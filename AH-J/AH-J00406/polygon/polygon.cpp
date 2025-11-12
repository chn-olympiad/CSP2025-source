#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[5005],dp1[5005][5005],dp2[505][50005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	if(n>500){
		dp1[0][0]=1;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			for(int j=0;j<=sum;j++){
				dp1[i][j]=dp1[i-1][j];
				if(j>=a[i])dp1[i][j]=(dp1[i][j]+dp1[i-1][j-a[i]])%mod;
			}
		}
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			for(int j=sum-1;j;j--){
				dp1[i][j]=(dp1[i][j]+dp1[i][j+1])%mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+dp1[i-1][a[i]+1])%mod;
		}
	}
	else{
		dp2[0][0]=1;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			for(int j=0;j<=sum;j++){
				dp2[i][j]=dp2[i-1][j];
				if(j>=a[i])dp2[i][j]=(dp2[i][j]+dp2[i-1][j-a[i]])%mod;
			}
		}
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			for(int j=sum-1;j;j--){
				dp2[i][j]=(dp2[i][j]+dp2[i][j+1])%mod;
			}
		}
		for(int i=3;i<=n;i++){
			ans=(ans+dp2[i-1][a[i]+1])%mod;
		}
	}
	printf("%d",ans);
	return 0;
}