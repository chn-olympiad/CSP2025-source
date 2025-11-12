#include<iostream>
#include<queue>
using namespace std;
int T,ans,n,cnt1,cnt2,cnt3;
struct node
{
	int x1,x2;
	const bool operator<(const node &o)const
	{
		return max(x1,x2)<max(o.x1,o.x2);
	}
};
priority_queue<node,vector<node>,less<node> >pq1,pq2,pq3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		while(pq1.size())
			pq1.pop();
		while(pq2.size())
			pq2.pop();	
		while(pq3.size())
			pq3.pop();					
		ans=cnt1=cnt2=cnt3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int a[5];
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
			if(a[1]>=a[2]&&a[1]>=a[3])
			{
				ans+=a[1];
				pq1.push({a[2]-a[1],a[3]-a[1]});
				cnt1++;
			}
			else if(a[2]>=a[1]&&a[2]>=a[3])
			{
				ans+=a[2];
				pq2.push({a[1]-a[2],a[3]-a[2]});
				cnt2++;				
			}
			else
			{
				ans+=a[3];
				pq3.push({a[2]-a[3],a[1]-a[3]});
				cnt3++;					
			}
		}
		while(cnt1>n/2)
		{
			cnt1--;
			ans+=max(pq1.top().x1,pq1.top().x2);
			pq1.pop();
		}
		while(cnt2>n/2)
		{
			cnt2--;
			ans+=max(pq2.top().x1,pq2.top().x2);
			pq2.pop();
		}
		while(cnt3>n/2)
		{
			cnt3--;
			ans+=max(pq3.top().x1,pq3.top().x2);
			pq3.pop();
		}
		printf("%d\n",ans);		
	}
	return 0;
}
