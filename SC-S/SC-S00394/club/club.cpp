#include<iostream> 
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

void solve()
{
	int n;
	scanf("%d",&n);
	vector<vector<int>>a(n+1,vector<int>(3));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	long long ans=0;
	vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>q(3);
	for(int i=1;i<=n;i++)
	{
		int mx=max(a[i][0],max(a[i][1],a[i][2]));
		for(int j=0;j<3;j++)
		{
			if(a[i][j]==mx)
			{
				q[j].emplace(a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]),i);
				ans+=a[i][j];
				break;
			}
		}
		for(int j=0;j<3;j++)
		{
			if(q[j].size()>n/2)
			{
				int t=q[j].top().second;
				ans-=q[j].top().first;
				q[j].pop();
				if(a[t][(j+1)%3]>a[t][(j+2)%3])
				{
					q[(j+1)%3].emplace(a[t][(j+1)%3]-max(a[t][j],a[t][(j+2)%3]),t);
				}
				else
				{
					q[(j+2)%3].emplace(a[t][(j+2)%3]-max(a[t][j],a[t][(j+1)%3]),t);
				}
			}
		}
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		solve();
	}
	return 0;
}
//14:54