# include <bits/stdc++.h>
# define mod 998244353
# define N 5010
# define ll long long
using namespace std;
inline int read() {
	int w=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) w=(w<<1)+(w<<3)+(ch^48);
	return w*f;
}
int n,mx,a[N];
ll dp[4][N<<1],ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) a[i]=read(),mx=max(mx,a[i]);
	sort(a+1,a+1+n),mx*=2,mx++;
	dp[0][0]=1;
	for(int i=1;i<=n;i++) {
	  for(int j=mx;j>=0;j--) {
	    if(min(mx,j+a[i])>a[i]*2) ans=(ans+dp[3][j])%mod;
	    dp[3][min(mx,j+a[i])]=(dp[3][min(mx,j+a[i])]+dp[3][j])%mod;
	  }
	  for(int j=0;j<=mx;j++) {
	    if(min(mx,j+a[i])>a[i]*2) ans=(ans+dp[2][j])%mod;
	    dp[3][min(mx,j+a[i])]=(dp[3][min(mx,j+a[i])]+dp[2][j])%mod;
	  }
	  for(int l=2;l>=1;l--) 
	    for(int j=0;j<=mx;j++) 
	      dp[l][min(mx,j+a[i])]=(dp[l][min(mx,j+a[i])]+dp[l-1][j])%mod;
	}
	printf("%lld",ans);
	return 0;
}
//5
//1 2 3 4 5

//5
//2 2 3 8 10

