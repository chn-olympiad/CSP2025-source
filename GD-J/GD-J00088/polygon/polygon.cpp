//T4 放这么简单的题啥意思 
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
const int N=5005,V=5000,mod=998244353;
int n,ans,bang,a[N],dp[N];
signed main()
{
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	n=rd,dp[0]=1;for(int i=1;i<=n;++i)a[i]=rd;sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		(ans+=bang)%=mod,(bang+=bang)%=mod;
		for(int j=V-a[i]+1;j<=V;++j)(bang+=dp[j])%=mod;
		for(int j=a[i]+1;j<=V;++j)(ans+=dp[j])%=mod;
		for(int j=V;j>=a[i];--j)(dp[j]+=dp[j-a[i]])%=mod;
	}
	cout<<ans<<'\n';return 0;
}
