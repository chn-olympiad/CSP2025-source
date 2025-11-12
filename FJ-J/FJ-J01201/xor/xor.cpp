# include <bits/stdc++.h>
# define N 500010
# define M 2000000
using namespace std;
inline int read() {
	int w=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) w=(w<<1)+(w<<3)+(ch^48);
	return w*f;
}
int pd[M];
int n,k,a[N],sum[N],dp[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	memset(pd,0xff,sizeof(pd)),pd[0]=0;
	for(int i=1;i<=n;i++) {
	  if(pd[sum[i]^k]!=-1) 
	    dp[i]=max(dp[i],dp[pd[sum[i]^k]]+1);
	  dp[i]=max(dp[i],dp[i-1]);
	  pd[sum[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}
//4 2
//2 1 0 3

//4 3
//2 1 0 3

//4 0
//2 1 0 3
