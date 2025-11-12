#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > pq[4];
int po[100010][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int tp=1;tp<=t;tp++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=3;i++) 
		{
			while(!pq[i].empty()) pq[i].pop();
		}
		
		for(int i=1;i<=n;i++)
		{
			cin>>po[i][1]>>po[i][2]>>po[i][3];
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int maxm=-1,secm=0;
			int maxmem=0;
			for(int j=1;j<=3;j++)
				if(po[i][j]>maxm) 
				{
					maxm=po[i][j];
					maxmem=j;
				}
			for(int j=1;j<=3;j++)
			{
				if(j==maxmem) continue;
				if(po[i][j]>secm)
				{
					secm=po[i][j];
				}
			}
			if(pq[maxmem].size()<n/2) 
			{
				pq[maxmem].push(maxm-secm);
				ans+=maxm;
			}
			else
			{
				pq[maxmem].push(maxm-secm);
				ans-=pq[maxmem].top();
				pq[maxmem].pop();
				ans+=maxm;
			}
			
		}
		cout<<ans<<endl;
	}
}
