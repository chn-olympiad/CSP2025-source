#include<bits/stdc++.h>
using namespace std;
const long long N=100010;
long long t,n,a[N][4];
struct node{
	long long id,d;
	bool operator <(const node &x) const{
		return x.d<d;
	}
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		long long cnt[4]={0},ans=0;
		priority_queue<node> q[4];
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++) for(long long j=1;j<=3;j++) scanf("%lld",&a[i][j]);
		for(int i=1;i<=n;i++)
		{
			long long max1=-1,max2=-1,pos1,pos2;
			for(long long j=1;j<=3;j++)
				if(a[i][j]>max1)
				{
					max1=a[i][j];
					pos1=j;
				}
			for(long long j=1;j<=3;j++)
				if(j!=pos1&&a[i][j]>max2)
				{
					max2=a[i][j];
					pos2=j;
				}
			if(cnt[pos1]<n/2)
			{
				q[pos1].push({i,max1-max2});
				ans+=max1;
				cnt[pos1]++;
			}
			else
			{
				node x=q[pos1].top();
				long long val1=max1-x.d;
				long long val2=max2;
				if(val1>val2)
				{
					q[pos1].pop();
					q[pos1].push({i,max1-max2});
					ans+=val1;
				}
				else
				{
					ans+=max2;
					cnt[pos2]++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
