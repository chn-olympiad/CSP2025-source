#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >q;
priority_queue<pair<int,int> >p;
priority_queue<pair<int,int> >l;
int a[100001][4];
int s[5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,i,j,t,x,ans,m,f;
	cin>>t;
	while(t--)
	{
	cin>>n;
	s[1]=0;
	s[2]=0;
	s[3]=0;
	m=n/2;
	 ans=0;
	 f=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{			ans+=a[i][1];
				if(f==0||f==1)
				{
				s[1]++;
				x=max(a[i][2],a[i][3]);
				q.push( {-(a[i][1]-x),i} );
				if(s[1]>m)
				{f=1;
					s[1]--;
					ans+=q.top().first;
					q.pop();
				}
			}
			}
			else
			if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1])
			{				ans+=a[i][2];
				if(f==0||f==2)
				{
				s[2]++;
				x=max(a[i][1],a[i][3]);
				p.push ( {-(a[i][2]-x),i} );
				if(s[2]>m)
				{f=2;
					s[2]--;
					ans+=p.top().first;
					p.pop();
				}
			}
			}
			else
			{
				ans+=a[i][3];
				if(f==0||f==3)
				{
				s[3]++;
				x=max(a[i][1],a[i][2]);
				l.push({-(a[i][3]-x),i});
				if(s[3]>m)
				{f=3;
					s[3]--;
					ans+=l.top().first;
					l.pop();
				}
			}
		}
		}
		while(!q.empty())
		{
			q.pop();
		}
		while(!p.empty())
		{
			p.pop();
		}
		while(!l.empty())
		{
			l.pop();
		}cout<<ans<<endl;
	}
	return 0;
 } 
    
