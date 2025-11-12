#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=998244353;
int a[N*10],s[N],dp[N][N*100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n>500){
        int ans=1;
        for(int i=1;i<=n;i++)ans=(1ll*ans*2)%M;
        ans=(ans-1-n-n*(n-1)/2+M)%M;
        printf("%d\n",ans);
        return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=(1ll*s[i-1]+1ll*a[i])%M;
	int ans=0;
	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=1;i<n;i++){
        for(int j=0;j<=5e4;j++){
            if(j<a[i])dp[i][j]=dp[i-1][j];
            else dp[i][j]=(1ll*dp[i-1][j]+1ll*dp[i-1][j-a[i]])%M;
        }
        if(i>1){
            for(int j=a[i+1]+1;j<=5e4;j++)ans=(1ll*ans+1ll*dp[i][j])%M;
        }
	}
	printf("%d\n",ans);
	return 0;
}
