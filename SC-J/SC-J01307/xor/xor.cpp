#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=5e6+5;;
int n,k,maxn;
int a[N],sum[N],dp[N],last[M];;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
		maxn=max(maxn,max(sum[i],sum[i]^k));
	}
	for(int i=1;i<=maxn;i++)
	{
		last[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(last[sum[i]^k]!=-1)
		{
			dp[i]=max(dp[i],dp[last[sum[i]^k]]+1);
		}
		last[sum[i]]=i;
	}
	cout<<dp[n];
	return 0;
}

/*
Problem 3[9:00]
Open Problem
I think this problem is easy for me to dp
*/
/*
//freopen
//feropen
Hey boy 
I wish you don't:
ben lai ying gai cong cong rong rong, you ren you yu(J)
xian zai shi cong cong mang mang,lian gun dai pa(S)
zheng yan shuo xia hua(Da dai ma)
ni zai gen yan shen me la(Chu kao chang)
ni zai ku shen me ku(Cha fen)
mei chu xi
*/