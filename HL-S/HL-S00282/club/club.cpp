#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,m;
int a[N][4];
struct abc
{
	int x,y,z;
	bool operator < (const abc &k) const
	{
		if(min(y,z)>0&&min(k.y,k.z)<0) return 0;
		if(min(y,z)==min(k.y,k.z)) return max(y,z)>max(k.y,k.z);
		return min(y,z)>min(k.y,k.z);
	}
};
priority_queue<abc>q1;
priority_queue<abc>q2;
priority_queue<abc>q3;
int ans;

void aaa()
{
	while(q1.size()>m||q2.size()>m||q3.size()>m)
	{
		while(q1.size()>m)
		{
			abc k=q1.top();
			q1.pop();
			if(k.y<k.z)
			{
				if(q2.size()<m)
					q2.push({k.x-k.y,-k.y,k.z-k.y});
				else
					q3.push({k.x-k.z,-k.z,k.y-k.z});
			}
			else
			{
				if(q3.size()<m)
					q3.push({k.x-k.z,-k.z,k.y-k.z});
				else
					q2.push({k.x-k.y,-k.y,k.z-k.y});
			}
		}
		while(q2.size()>m)
		{
			abc k=q2.top();
			q2.pop();
			if(k.y<k.z)
			{
				if(q1.size()<m)
					q1.push({k.x-k.y,-k.y,k.z-k.y});
				else
					q3.push({k.x-k.z,-k.z,k.y-k.z});
			}
			else
			{
				if(q3.size()<m)
					q3.push({k.x-k.z,-k.z,k.y-k.z});
				else
					q1.push({k.x-k.y,-k.y,k.z-k.y});
			}
		}
		while(q3.size()>m)
		{
			abc k=q3.top();
			q3.pop();
			if(k.y<k.z)
			{
				if(q1.size()<m)
					q1.push({k.x-k.y,-k.y,k.z-k.y});
				else
					q2.push({k.x-k.z,-k.z,k.y-k.z});
			}
			else
			{
				if(q2.size()<m)
					q2.push({k.x-k.z,-k.z,k.y-k.z});
				else
					q1.push({k.x-k.y,-k.y,k.z-k.y});
			}
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		ans=0;
		scanf("%d",&n);
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) q1.push({a[i][1],a[i][1]-a[i][2],a[i][1]-a[i][3]});
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) q2.push({a[i][2],a[i][2]-a[i][1],a[i][2]-a[i][3]});
			else q3.push({a[i][3],a[i][3]-a[i][1],a[i][3]-a[i][2]});
		}
		aaa();
		while(q1.size())
		{
			ans+=q1.top().x;
			q1.pop();
		}
		while(q2.size())
		{
			ans+=q2.top().x;
			q2.pop();
		}
		while(q3.size())
		{
			ans+=q3.top().x;
			q3.pop();
		}
		printf("%d\n",ans);
	}
	return 0;
}