#include<bits/stdc++.h>
using namespace std;
int n;
int c[4];
long long ans,sum;
struct node
{
	int x,y,z;
	int ma;
}a[100009];
bool cmp(node a,node b)
{
	return a.ma>b.ma;
}
 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		ans=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].ma=max(a[i].x,max(a[i].y,a[i].z));
			if(a[i].y==0&&a[i].z==0) sum++;
			
		}
		if(sum==n)
		{
			for(int i=1;i<=n;i++)
			{
				ans+=a[i].x;
			}
			cout<<ans<<endl;
		}
		else
		{
			sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].ma==a[i].x)
			{
				if(c[1]<n/2)
				c[1]++,ans+=a[i].x;
				else
				{
					if(a[i].y>a[i].z)
					{
						if(c[2]<n/2)
						c[2]++,ans+=a[i].y;
						else 
						c[3]++,ans+=a[i].z;
					}
					else
					{
						if(c[3]<n/2)
						c[3]++,ans+=a[i].z;
						else 
						c[2]++,ans+=a[i].y;
					}
				}
			}
			if(a[i].ma==a[i].y)
			{
				if(c[2]<n/2)
				c[2]++,ans+=a[i].y;
				else
				{
					if(a[i].x>a[i].z)
					{
						if(c[1]<n/2)
						c[1]++,ans=a[i].x;
						else 
						c[3]++,ans=a[i].z;
					}
					else
					{
						if(c[3]<n/2)
						c[3]++,ans+=a[i].z;
						else 
						c[1]++,ans+=a[i].x;
					}
				}
			}
			if(a[i].ma==a[i].z)
			{
				if(c[3]<n/2)
				c[3]++,ans+=a[i].z;
				else
				{
					if(a[i].y>a[i].x)
					{
						if(c[2]<n/2)
						c[2]++,ans+=a[i].y;
						else 
						c[1]++,ans+=a[i].x;
					}
					else
					{
						if(c[1]<n/2)
						c[1]++,ans+=a[i].x;
						else 
						c[2]++,ans+=a[i].y;
					}
				}
			}
		}
		cout<<ans<<"\n";
		}
	} 
	return 0;
} 