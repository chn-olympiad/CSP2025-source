#include<bits/stdc++.h>
#define N 505
//#define LL long long
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define mod 998244353
using namespace std;

int n,a[N],ans,dp[N*N][4];

int qpow(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=a*res%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	if(a[n]==1) ans=qpow(2,n)-1-((n-1)*n/2);
	else if(n==3){
		if(a[1]+a[2]>a[3]) ans=1;
		else ans=0;
	}
	else if(n<=20){
		for(int u=1;u<(1<<n);u++){
			int sum=0,mx=-1e9;
			for(int i=1;i<=n;i++){
				if(u&(1<<(i-1))){
					sum+=a[i];
					mx=max(mx,a[i]);
				}
			}
			if(sum>2*mx){
				ans++;
				if(ans>mod) ans-=mod;
			}
		}
	}
	else{
//		cout<<"czy";
		int sum=0;
		ans=-0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				dp[a[i]+a[j]]++;
//			}
//		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=sum;j>=0;j--){
				for(int k=1;k<=3;k++){
					if((j>a[i]*2||(k<=2&&j>=a[i]))){
						dp[j][k]+=dp[j-a[i]][k-1];
						if(k==3) dp[j][k]+=dp[j-a[i]][k];
						ans=max(ans,dp[j][k]);
					}
				}
			}
		}
	}
	printf("%lld",ans%mod);
//	printf("\ntime:%.0lfms",(double)clock());
	return 0;
}//知颖你太美