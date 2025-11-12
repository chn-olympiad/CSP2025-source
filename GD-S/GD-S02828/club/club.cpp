#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long int nums[100001][3]={0},chag;
vector<long long int> club[3];
long long int second_max(long long int id)
{
	long long int pre_val=nums[id][chag],now_id=-1;
	for(long long int i=0;i<3;i++)
	{
		if(i!=chag&&nums[id][i]<=pre_val)
		{
			if(now_id==-1)
			{
				now_id=i;
			}
			now_id=nums[id][now_id]>nums[id][i]?now_id:i;
		}
	}
	return now_id;
}
long long int cha(long long int id)
{
	long long int pre_val=nums[id][chag],now_val=nums[id][second_max(id)];
	return pre_val-now_val;
}
bool cmp(long long int a,long long int b)
{
	long long int ca=cha(a),cb=cha(b);
	if(ca==cb)
	{
		return a<b;
	}
	return ca>cb;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int t,sum=0;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld %lld %lld",&nums[i][0],&nums[i][1],&nums[i][2]);
			long long int maxn=max(nums[i][0],max(nums[i][1],nums[i][2]));
			if(maxn==nums[i][0])
			{
				club[0].push_back(i);
			}
			else if(maxn==nums[i][1])
			{
				club[1].push_back(i);
			}
			else
			{
				club[2].push_back(i);
			}
			sum+=maxn;
		}
		for(long long int i=0;i<3;i++)
		{
			if(club[i].size()>n/2)
			{
				chag=i;
				sort(club[i].begin(),club[i].end(),cmp);
				while(club[i].size()>n/2)
				{
					int a=second_max(club[i].back()),b=cha(club[i].back());
					club[a].push_back(club[i].back()),club[i].pop_back(),sum-=b;
				}
				i=0;
			}
		}
		printf("%lld\n",sum);
		club[0].clear(),club[1].clear(),club[2].clear(),sum=0;
	}
	return 0;
}
/**/
