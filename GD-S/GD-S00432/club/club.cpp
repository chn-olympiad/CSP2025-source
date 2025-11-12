#include <bits/stdc++.h>
using namespace std;
long long t,n,first[100001],second[100001],a[100001][4],cnt1,cnt2,cnt3,ans;
struct Point
{
	long long id,v;
};
struct cmp
{
	bool operator()(Point &a,Point &b)
	{
		return a.v>b.v;
	}
};
priority_queue<Point,vector<Point>,cmp>q1,q2,q3;
int main()
{
	//思路：贪心 /优先队列 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		while (!q1.empty())
		{
			q1.pop();
		}
		while (!q2.empty())
		{
			q2.pop();
		}
		while (!q3.empty())
		{
			q3.pop();
		}
		ans=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		memset(first,0,sizeof(first));
		memset(second,0,sizeof(second));
		memset(a,0,sizeof(a));
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			first[i]=max(a[i][1],max(a[i][2],a[i][3]));
			if (first[i]==a[i][1])
			{
				first[i]=1;
				second[i]=max(a[i][2],a[i][3]);
				if(second[i]==a[i][2])
				{
					second[i]=2;
				}
				else
				{
					second[i]=3;
				}
			}
			else if (first[i]==a[i][2])
			{
				first[i]=2;
				second[i]=max(a[i][1],a[i][3]);
				if(second[i]==a[i][1])
				{
					second[i]=1;
				}
				else
				{
					second[i]=3;
				}
			}
			else
			{
				first[i]=3;
				second[i]=max(a[i][1],a[i][2]);
				if(second[i]==a[i][1])
				{
					second[i]=1;
				}
				else
				{
					second[i]=2;
				}
			}
		}
		for (int i=1;i<=n;i++)
		{
			if (first[i]==1)
			{
				q1.push((Point){i,a[i][first[i]]-a[i][second[i]]});
				ans+=a[i][first[i]];
				cnt1++;
				if (cnt1>n/2)
				{
					long long id=q1.top().id;
					long long v=q1.top().v;
					q1.pop();
					ans-=v;
					if (second[id]==2)
					{
						cnt2++;
					}
					else
					{
						cnt3++;
					}
					cnt1--;
				}
			}
			else if (first[i]==2)
			{
				q2.push((Point){i,a[i][first[i]]-a[i][second[i]]});
				ans+=a[i][first[i]];
				cnt2++;
				if (cnt2>n/2)
				{
					long long id=q2.top().id;
					long long v=q2.top().v;
					q2.pop();
					ans-=v;
					if (second[id]==1)
					{
						cnt1++;
					}
					else
					{
						cnt3++;
					}
					cnt2--;
				}
			}
			else
			{
				q3.push((Point){i,a[i][first[i]]-a[i][second[i]]});
				ans+=a[i][first[i]];
				cnt3++;
				if (cnt3>n/2)
				{
					long long id=q3.top().id;
					long long v=q3.top().v;
					q3.pop();
					ans-=v;
					if (second[id]==2)
					{
						cnt2++;
					}
					else
					{
						cnt1++;
					}
					cnt3--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
