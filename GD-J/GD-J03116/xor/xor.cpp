#include<cstdio>
#include<unordered_map>
using namespace std;
long long int nums[500001]={0};
unordered_map<long long int,bool> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long int n,k;
	scanf("%lld %lld",&n,&k);
	for(long long int i=1;i<=n;i++)
	{
		scanf("%lld",nums+i);
		nums[i] ^= nums[i-1];
	}
	long long int cnt=0,s=0;
	for(long long int i=1;i<=n;i++)
	{
		long long int ni=nums[i]^nums[s];
		long long int a=ni^k;
		if(mp.count(a)||ni==k)
		{
			cnt++,mp.clear(),s=i;
		}
		else
		{
			mp[ni]=1;
		}
	}
	printf("%lld",cnt);
	return 0;
}
