#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct node
{
	int x,y,z,maxid,value;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		priority_queue<int,vector<int>,greater<int>> q;
		int n=read();
		for(int i=1;i<=n;i++)
		{
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			if(a[i].x>=max(a[i].y,a[i].z))
			{
				a[i].maxid=1;
				a[i].value=a[i].x-max(a[i].y,a[i].z);
			}
			if(a[i].y>=max(a[i].x,a[i].z))
			{
				a[i].maxid=2;
				a[i].value=a[i].y-max(a[i].x,a[i].z);
			}
			if(a[i].z>=max(a[i].x,a[i].y))
			{
				a[i].maxid=3;
				a[i].value=a[i].z-max(a[i].x,a[i].y);
			}
		}
		int na=0,nb=0,nc=0,k=n/2,ans=0,tid=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].maxid==1)
			na++;
			else
		    if(a[i].maxid==2)
			nb++;
			else
			if(a[i].maxid==3)
			nc++;
		}
		if(na>k)
		tid=1;
		if(nb>k)
		tid=2;
		if(nc>k)
		tid=3;
		na=0;
		nb=0;
		nc=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].maxid==1)
			{
				if(tid==1)
				q.push(a[i].value);
				na++;
				if(na>k)
				{
					na--;
					ans+=a[i].x-a[i].value;
					if(a[i].value>q.top())
					ans+=a[i].value-q.top();
					q.pop();
				}
				else
				ans+=a[i].x;
			}
			if(a[i].maxid==2)
			{
				if(tid==2)
				q.push(a[i].value);
				nb++;
				if(nb>k)
				{
					na--;
					ans+=a[i].y-a[i].value;
					if(a[i].value>q.top())
					ans+=a[i].value-q.top();
					q.pop();
				}
				else
				ans+=a[i].y;
			}
			if(a[i].maxid==3)
			{
				if(tid==3)
				q.push(a[i].value);
				nc++;
				if(nc>k)
				{
					nc--;
					ans+=a[i].z-a[i].value;
					if(a[i].value>q.top())
					ans+=a[i].value-q.top();
					q.pop();
				}
				else
				ans+=a[i].z;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
