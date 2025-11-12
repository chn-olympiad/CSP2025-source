#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001],c[200001];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int w;
	cin>>w;
	while(w--)
	{
		int n;
		bool f=1;
		int s1=0,s2=0,s3=0;
		scanf("%d",&n);int k=n/2;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >qa;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >qb;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >qc;
		priority_queue<int,vector<int>>mm;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			mm.push(a[i]);if(!(b[i]==c[i]&&b[i]==0))f=0;
			int maxx=max(max(a[i],b[i]),c[i]);
			if(maxx==a[i])//go to A
			{
				if(s1==k)
				{
					int x=qa.top().first;
					int y=qa.top().second;
					int p1=b[i];
					int p2=c[i];
					int p3=b[y]-a[y]+a[i];
					int p4=c[y]-a[y]+a[i];
					int maxx=max(max(max(p3,p4),p2),p1);
					if(maxx==p1)
					{
						s2++;
						qb.push(make_pair(b[i],i));
					}
					else if(maxx==p2)
					{
						s3++;
						qc.push(make_pair(c[i],i));
					}
					else if(maxx==p3)
					{
						qa.pop();
						s2++;
						qb.push(make_pair(b[y],y));
						qa.push(make_pair(a[i],i));
					}
					else
					{
						qa.pop();
						s3++;
						qc.push(make_pair(c[y],y));
						qa.push(make_pair(a[i],i));
					}
				}
				else
				{
					qa.push(make_pair(a[i],i));
					s1++;
				}
				
			}
			if(maxx==b[i])//go to B
			{
				if(s2==k)
				{
					int x=qb.top().first;
					int y=qb.top().second;
					int p1=a[i];
					int p2=c[i];
					int p3=a[y]-b[y]+b[i];
					int p4=c[y]-b[y]+b[i];
					int maxx=max(max(max(p3,p4),p2),p1);
					if(maxx==p1)
					{
						s1++;
						qa.push(make_pair(a[i],i));
					}
					else if(maxx==p2)
					{
						s3++;
						qc.push(make_pair(c[i],i));
					}
					else if(maxx==p3)
					{
						qb.pop();
						s1++;
						qa.push(make_pair(a[y],y));
						qb.push(make_pair(b[i],i));
					}
					else
					{
						qb.pop();
						s3++;
						qc.push(make_pair(c[y],y));
						qb.push(make_pair(b[i],i));
					}
				}
				else
				{
					qb.push(make_pair(b[i],i));
					s2++;
				}
				
			}
			if(maxx==c[i])//go to C
			{
				if(s3==k)
				{
					int x=qc.top().first;
					int y=qc.top().second;
					int p1=a[i];
					int p2=b[i];
					int p3=b[y]-c[y]+c[i];
					int p4=a[y]-c[y]+c[i];
					int maxx=max(max(max(p3,p4),p2),p1);
					if(maxx==p1)
					{
						s1++;
						qa.push(make_pair(a[i],i));
					}
					else if(maxx==p2)
					{
						s2++;
						qb.push(make_pair(b[i],i));
					}
					else if(maxx==p3)
					{
						qc.pop();
						s2++;
						qb.push(make_pair(b[y],y));
						qc.push(make_pair(c[i],i));
					}
					else
					{
						qc.pop();
						s1++;
						qa.push(make_pair(a[y],y));
						qc.push(make_pair(c[i],i));
					}
				}
				else
				{
					qc.push(make_pair(c[i],i));
					s3++;
				}
			}
		}
		if(f==1)
		{
			int ss=0;
			for(int i=1;i<=k;i++)
			{
				ss+=mm.top();
				mm.pop();
			}
			printf("%d\n",ss);
			continue;
		}
		int sum=0;//cout<<endl;
		while(!qa.empty())
		{
			int x=qa.top().first;
			int y=qa.top().second;
			qa.pop();
		//	cout<<y<<" ";
			sum+=x;
		}//cout<<endl;
		while(!qb.empty())
		{
			int x=qb.top().first;
			int y=qb.top().second;
			qb.pop();
		//	cout<<y<<" ";
			sum+=x;
		}//cout<<endl;
		while(!qc.empty())
		{
			int x=qc.top().first;
			int y=qc.top().second;
			qc.pop();
		//	cout<<y<<" ";
			sum+=x;
		}//cout<<endl;
		printf("%d\n",sum);
	}
	return 0;
}