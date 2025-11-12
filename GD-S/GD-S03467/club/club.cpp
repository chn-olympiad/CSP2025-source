#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct club
{
	int x,y,z;
}a[110000];
struct choose
{
	int x;
	int num;
};
int cnt[10];
long long ans;
void dfs(int now,long long sum)
{
	if (now>n)
	{
		ans=max(ans,sum);
		return;
	}
	for (int i=1;i<=3;i++)
	{
		int t;
		if (i==1)
			t=a[now].x;
		else
			if (i==2)
				t=a[now].y;
			else
				t=a[now].z;
		if (cnt[i]+1>n/2)
			continue;
		cnt[i]++;
		dfs(now+1,sum+t);
		cnt[i]--;
	}
}
priority_queue<int,vector<int>,greater<int> >p; 
bool operator>(choose x,choose y)
{
	return x.x>y.x;
}
priority_queue<choose,vector<choose>,greater<choose> >q1,q2,q3;
void find(int i)
{
	int mx=max(a[i].x,max(a[i].y,a[i].z));
	if (mx==a[i].x)
	{
		if (q1.size()>=n/2)
		{
			choose t=q1.top();
			if (t.x<mx)
			{
				q1.pop();
				q1.push({mx,i});
				find(t.num);
				return;	
			}
		}
		else 
		{
			q1.push({mx,i});
			return;
		}	
	}
	if (mx==a[i].y)
	{
		if (q2.size()>=n/2)
		{
			choose t=q2.top();
			if (t.x<mx)
			{
				q2.pop();
				q2.push({mx,i});
				find(t.num);
				return;	
			}
		}
		else 
		{
			q2.push({mx,i});
			return;
		}	
	}
	if (mx==a[i].z)
	{
		if (q3.size()>=n/2)
		{
			choose t=q2.top();
			if (t.x<mx)
			{
				q3.pop();
				q3.push({mx,i});
				find(t.num);
				return;	
			}
		}
		else 
		{
			q3.push({mx,i});
			return;
		}	
	}
}
bool cmp1(club x,club y)
{
	return x.x>y.x;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		memset(cnt,0,sizeof(cnt));
		ans=0;
		scanf("%d",&n);
		int mx1=-1,mx2=-1,mx3=-1;
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			find(i); 
			mx1=max(mx1,a[i].x);
			mx2=max(mx2,a[i].y);
			mx3=max(mx3,a[i].z);
		}
		while (!q1.empty())
		{
			ans+=q1.top().x;
			q1.pop();
		}
		while (!q2.empty())
		{
			ans+=q2.top().x;
			q2.pop();
		}
		while (!q3.empty())
		{
			ans+=q3.top().x;
			q3.pop();
		}
		if (n<=10)
		{
			dfs(1,0);
			printf("%lld\n",ans);	
			continue;
		}
		if (mx2==0&&mx3==0)
		{
			long long sum=0;
			sort(a+1,a+n+1,cmp1);
			for (int i=1;i<=n/2;i++)
				sum+=a[i].x;
			for (int i=n/2+1;i<=n;i++)
				sum+=a[i].y;
			printf("%lld\n",sum);
			continue;
		}
		printf("%lld\n",ans);	
	}
	return 0;
 } 
//25pts 
