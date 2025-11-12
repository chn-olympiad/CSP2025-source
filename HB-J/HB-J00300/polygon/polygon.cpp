#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
#define maxn 5005
#define int long long
#define mod 998244353
using namespace std;

int n,a[maxn],dp[maxn][maxn];
int ans=0,sum=0;

void solve(int pos,int mx){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=pos;i++){
		for(int j=0;j<=mx;j++){
			if(j+a[i]>mx) dp[i][mx]=(dp[i][mx]+dp[i-1][j]+1)%mod;
			else dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%mod;
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		}
		dp[i][mx]=(dp[i][mx]+dp[i-1][mx])%mod;
		dp[i][mx]=(dp[i][mx]+dp[i-1][mx]+1)%mod;
	}
	ans=dp[pos][mx];
}
int read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch-48),ch=getchar();
	return x*f;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<3) {printf("0"); return 0;}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		ans=0;
		solve(i-1,a[i]);
		sum=(sum+ans)%mod;
	}
	printf("%lld\n",sum);
	return 0;
}