#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5;
int a[maxn+5][4];
vector<int> clubs[4];
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int satisfy_sum=0;
		for (int i=1;i<=3;i++) clubs[i].clear();
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=3;j++) cin>>a[i][j];
			if (a[i][1]>a[i][2]&&a[i][1]>a[i][3])
			{
				clubs[1].push_back(i);
				satisfy_sum+=a[i][1];
			}
			else
			{
				clubs[a[i][2]>a[i][3]?2:3].push_back(i);
				satisfy_sum+=max(a[i][2],a[i][3]);
			}
		}
		while(!q.empty()) q.pop();
		for (int i=1;i<=3;i++)
		{
			if (clubs[i].size()>n/2)
			{
				int cnt=clubs[i].size()-n/2;
				for (int j:clubs[i])
				{
					int mindif=INT_MAX;
					for (int k=1;k<=3;k++)
					{
						if (k==i) continue;
						mindif=min(mindif,a[j][i]-a[j][k]);
					}
					q.push(mindif);
				}
				for (int i=0;i<cnt;i++)
				{
					satisfy_sum-=q.top();
					q.pop();
				}
				break;
			}
		}
		cout<<satisfy_sum<<endl;
	}
	return 0;
}
