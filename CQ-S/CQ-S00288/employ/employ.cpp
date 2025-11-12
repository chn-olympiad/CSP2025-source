/*
employ
奇怪，感觉不难。
每个人只有在前面若干个位置时才可能……
不对，它前面要是有人放弃也算是炸的，这很麻烦。
卧槽今年 CCF 怎么出这么难，扯。
感觉后面三个都有紫吧，我头疼。
但是这个题可以先做个 $m=1$ 和 $m=n$ 的，再拼上暴力有 24pts。
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=510,mod=998244353;
int s[N],c[N],cnt[N],p[N];
ll dp[N][N];
inline void modadd(ll &x,ll y){x=(x+y)%mod;return;}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%1d",s+i);
	for(int i=1;i<=n;i++)scanf("%d",c+i),cnt[c[i]]++;
	ll fac=1;
	for(int i=1;i<=n;i++)fac=fac*i%mod;
	if(m==n)
	{
		bool fs=true;
		for(int i=1;i<=n;i++)fs&=s[i];
		if(!fs||cnt[0]){printf("0");return 0;}
		printf("%lld\n",fac);
		return 0;
	}
	iota(p+1,p+n+1,1);
	int ans=0;
	do
	{
		int fcnt=0,scnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]&&c[p[i]]>fcnt)scnt++;
			else fcnt++;
		}
		ans+=(scnt>=m);
	}
	while(next_permutation(p+1,p+n+1));
	printf("%d\n",ans);
	return 0;
}