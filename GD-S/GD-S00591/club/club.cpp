#include <bits/stdc++.h>
using namespace std;

struct member
{
	int x,y,z;
}a[100005];
member t1[100005],t2[100005];

int n,maxn=-2e9;
void dfs(int step,int x,int y,int z,int sum)
{
	if (step>n) 
	{
		maxn=max(maxn,sum);
		return ;
	}
	if (x!=n/2) dfs(step+1,x+1,y,z,sum+a[step].x);
	if (y!=n/2) dfs(step+1,x,y+1,z,sum+a[step].y);
	if (z!=n/2) dfs(step+1,x,y,z+1,sum+a[step].z);
}
bool cmp(member x,member y)
{
	return x.x>y.x;
};
bool cmp2(member x,member y)
{
	return x.x-x.y>y.x-y.y;
};
bool cmp3(member x,member y)
{
	return x.y-x.x>y.y-y.x;
};

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	bool y=true;
	cin >> T;
	while (T--)
	{
		int cur1=0,cur2=0;
		maxn=-2e9;
		cin >> n;
		for (int i=1;i<=n;i++) 
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y>0 || a[i].z>0) y=false;
		}
		if (n<=30) 
		{
			dfs(1,0,0,0,0);
			cout << maxn << endl;
		}
		else if (y)
		{
			sort(a+1,a+n+1,cmp);
			int ans = 0;
			for (int i=1;i<=n/2;i++) ans+=a[i].x;
			cout << ans << endl;
		}
		else
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i].x>a[i].y) t1[++cur1]=a[i];
				else t2[++cur2]=a[i];
			}
			if (cur1>n/2) 
			{
				sort(t1+1,t1+cur1+1,cmp2);
				while(cur1>n/2)
				{
					t2[++cur2]=t1[cur1];
					cur1--;
				}
			}
			else if (cur2>n/2)
			{
				sort(t2+1,t2+cur2+1,cmp3);
				while(cur2>n/2)
				{
					t1[++cur1]=t2[cur2];
					cur2--;
				}
			}
			int ans = 0;
			for (int i=1;i<=cur1;i++)
			{
				ans+=t1[i].x;
			}
			for (int i=1;i<=cur2;i++)
			{
				ans+=t2[i].y;
			}
			cout << ans << "\n";
		}
	}
}
