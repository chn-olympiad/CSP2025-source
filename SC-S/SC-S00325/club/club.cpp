#include<bits/stdc++.h>
using namespace std;
int m;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		pair <int,int> p[10005][3];
		int s=0,n,ans=0,mmm=20000;
		int w=0,x=0,y=0;
		priority_queue<int> q;
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			for(int t=1;t<=3;t++)
			{
				cin>>p[j][t].first;
				p[j][t].second=t;
			}
		}
		for(int j=1;j<=n;j++)
		{
			sort(p[j]+1,p[j]+4); 
		} 
		for(int j=1;j<=n;j++)
		{
			ans+=p[j][3].first; 
			if(p[j][3].second==1){w++;}
			if(p[j][3].second==2){x++;}
			if(p[j][3].second==3){y++;}
		}
		if(w>n/2)
		{
			s=w-n/2;
			for(int j=1;j<=n;j++)
			{
				if(p[j][3].second==1)
				{
					q.push(p[j][2].first-p[j][3].first);
				}
			}
		}
		if(x>n/2)
		{
			s=x-n/2;
			for(int j=1;j<=n;j++)
			{
				if(p[j][3].second==2)
				{
					q.push(p[j][2].first-p[j][3].first);
				}
			}
		}
		if(y>n/2)
		{
			s=y-n/2;
			for(int j=1;j<=n;j++)
			{
				if(p[j][3].second==3)
				{
					q.push(p[j][2].first-p[j][3].first);
				}
			}
		}
		for(int j=1;j<=s;j++)
		{
			ans+=q.top();
			q.pop();
		}
		cout<<ans;
	}
	return 0;
} 