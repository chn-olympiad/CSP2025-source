#include<iostream>
#include<queue>
using namespace std;
#define maxn (int)1e5
int t,n;
long long a[maxn+10][3];
priority_queue<long long,vector<long long>,greater<long long>>q[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long ans=0;
		for(int i=0;i<3;i++)
			while(!q[i].empty())q[i].pop();
		for(int i=0;i<n;i++)
		{
			int d1=0,d2=0;
			for(int j=0;j<3;j++)
			{
				scanf("%lld",&a[i][j]);
				if(a[i][d1]<a[i][j])d1=j;
				if(a[i][d2]>a[i][j])d2=j;
			}
			ans+=a[i][d1];
			q[d1].push(a[i][d1]-a[i][3-d1-d2]);
			while(q[d1].size()>n/2)
			{
				ans-=q[d1].top();
				q[d1].pop();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
