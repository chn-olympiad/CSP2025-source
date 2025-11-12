#include<stdio.h>
#include<algorithm>
using namespace std;
int a[5005];
int b[5005];
long long dp[505][1000];
int n;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		dp[i][a[i]]=1;
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=b[i-1];j++) dp[i][j]=dp[i][j]+dp[i-1][j];
		for(int j=a[i];j<=b[i];j++) dp[i][j]=dp[i][j]+dp[i-1][j-a[i]];
	}
	/*while(1){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<' '<<b[x]<<endl;
	}*/
	long long ans=0;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=b[i-1];j++){
			ans=(ans+dp[i-1][j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}

