#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
const int N=5e5+100;
int n,k,a[N],p,num,dp[N];
unordered_map<int,int> um;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	um[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		num=a[i]^k;
		if(um.count(num)) 
		{
			p=um[num];
			//printf("%d %d\n",i,p);
			dp[i]=max(dp[i],dp[p]+1);
		}
		um[a[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}
