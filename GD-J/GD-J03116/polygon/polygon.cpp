#include<cstdio>
#include<algorithm>
using namespace std;
#define N 998244353
long long int nums[5010]={0},ans=0,n,m;
bool vis[5010]={0};
void dfs(long long int k,long long int sum,long long int i)
{
	if(k>=2)
	{
		long long int dis=lower_bound(nums+i,nums+n,sum)-nums;
		if(nums[n-1]<sum)
		{
			dis=n;
		}
		ans += dis - i,ans%=N;
		if(k==m)
		return;
	}
	for(long long int j=i;j<n;j++)
	{
		if(vis[j]==0)
		{
			vis[j]=1;
			dfs(k+1,sum+nums[j],j+1);
			vis[j]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long int i=0;i<n;i++)
	{
		scanf("%lld",nums+i);
	}
	sort(nums,nums+n);
	m=n-1,dfs(0,0,0);
	printf("%lld",ans);
	return 0;
}
