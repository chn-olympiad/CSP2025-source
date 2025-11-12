#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[100001][4];
		bool flag2=true,flag3=true;
		int bucket[4]={0,0,0,0},preference[100001],sec[100001],sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0)flag2=false;
			if(a[i][3]!=0)flag3=false;
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3])
			{
				preference[i]=1;
				bucket[1]++;
				sum+=a[i][1];
				if(a[i][2]>=a[i][3])
				{
					sec[i]=2;
				}
				else
				{
					sec[i]=3;
				}
			}
			if(a[i][2]>=a[i][1] && a[i][2]>a[i][3])
			{
				preference[i]=2;
				bucket[2]++;
				sum+=a[i][2];
				if(a[i][1]>=a[i][3])
				{
					sec[i]=1;
				}
				else
				{
					sec[i]=3;
				}
			}
			if(a[i][3]>a[i][2] && a[i][3]>a[i][1])
			{
				preference[i]=3;
				bucket[3]++;
				sum+=a[i][3];
				if(a[i][2]>=a[i][1])
				{
					sec[i]=2;
				}
				else
				{
					sec[i]=1;
				}
			}
		}
		if(flag2 && flag3)
		{
			priority_queue<int>pq;
			for(int i=1;i<=n;i++)
			{
				pq.push(a[i][1]);
			}
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=pq.top();
				pq.pop();
			}
			cout<<ans;
			continue;
		}
		priority_queue<int,vector<int>,greater<int> >pq;
		if(flag3)
		{
			int prefer=0;
			if(bucket[1]>n/2)
			{
				prefer=1;
			}
			if(bucket[2]>n/2)
			{
				prefer=2;
			}
			if(prefer==0)
			{
				cout<<sum<<endl;
				continue;
			}
			int m=bucket[prefer]-n/2;
			for(int i=1;i<=n;i++)
			{
				pq.push(a[i][preference[i]]-a[i][3-preference[i]]);
			}
			for(int i=1;i<=m;i++)
			{
				sum-=pq.top();
				pq.pop();
			}
			cout<<sum<<endl;
			continue;
		}
		int prefer=0;
		if(bucket[1]>n/2)
		{
			prefer=1;
		}
		if(bucket[2]>n/2)
		{
			prefer=2;
		}
		if(bucket[3]>n/2)
		{
			prefer=3;
		}
		if(prefer==0)
		{
			cout<<sum<<endl;
			continue;
		}
		int m=bucket[prefer]-n/2;
		for(int i=1;i<=n;i++)
		{
			pq.push(a[i][preference[i]]-a[i][sec[i]]);
		}
		for(int i=1;i<=m;i++)
		{
			sum-=pq.top();
			pq.pop();
		}
		cout<<sum<<endl;
	}
	return 0;
 } 
