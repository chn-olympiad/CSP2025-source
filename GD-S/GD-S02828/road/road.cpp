#include<cstdio>
#include<algorithm>
using namespace std;
struct bian
{
	long long int u,v,val;
}nums[10001];
bool cmp(bian a,bian b)
{
	return a.val<b.val;
}
long long int jh[10001]={0};
long long int town[15][10001]={0}; 
long long int track(long long int a)
{
	if(jh[a]==a)
	{
		return a;
	}
	return jh[a]=track(jh[a]);
}
void join(long long int a,long long int b)
{
	long long int la=track(a),lb=track(b);
	if(la<lb)
	{
		jh[lb]=la;
	}
	else
	{
		jh[la]=lb;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long int n,m,k,sum=0;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(long long int i=0;i<m;i++)
	{
		scanf("%lld %lld %lld",&nums[i].u,&nums[i].v,&nums[i].val);
	}
	for(long long int i=0;i<k;i++)
	{
		for(long long int j=0;j<=n;j++)
		{
			scanf("%lld",&town[i][j]);
		}
	}
	for(long long int j=0;j<=n;j++)
	{
		jh[j]=j;
	}
	sort(nums,nums+m,cmp);
	for(long long int i=0;i<m;i++)
	{
		if(track(nums[i].u)!=track(nums[i].v))
		{
			join(nums[i].u,nums[i].v),sum+=nums[i].val;
		}
	}
	printf("%lld",sum);
	return 0;
}
