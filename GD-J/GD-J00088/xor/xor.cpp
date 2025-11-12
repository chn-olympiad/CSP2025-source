#include<bits/stdc++.h>
#define rd read()
#define int long long
using namespace std;
inline int read()
{
	int x=0,ss=1,s=getchar();
	while((s<'0'||s>'9')&&s!='-')s=getchar();
	if(s=='-')ss=-1,s=getchar();
	while(s>='0'&&s<='9')x=x*10+(s^48),s=getchar();
	return x*ss;
}
const int N=500005,V=1500005;
int n,k,dp[N],a[N],lst[V];
signed main()
{
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	n=rd,k=rd;memset(lst,-1,sizeof(lst)),lst[0]=0;
	for(int i=1;i<=n;++i)a[i]=a[i-1]^rd;
	for(int i=1;i<=n;lst[a[i]]=i,++i)
	{
		dp[i]=dp[i-1];
		if(lst[a[i]^k]>=0)dp[i]=max(dp[i],dp[lst[a[i]^k]]+1);
	}
	cout<<dp[n]<<'\n';
	return 0;
}
