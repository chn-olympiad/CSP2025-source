#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z,b,c;
}a[100010];
int ans;
bool cmp(node x,node y)
{
	return (x.b-x.c)>(y.b-y.c);
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
		ans=0;
		int n,i;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			int t1=max(a[i].x,max(a[i].y,a[i].z));
			int t2=min(a[i].x,min(a[i].y,a[i].z));
			int t3=a[i].x+a[i].y+a[i].z;
			a[i].b=t1;
			a[i].c=t3-t2-t1;
		}
		sort(a+1,a+n+1,cmp);
		int s1=0,s2=0,s3=0,m=n/2;
		for(i=1;i<=n;i++)
		{
			if(a[i].x==a[i].b)
			{
				if(s1<m)
				{
					s1++;
					ans+=a[i].x;
					continue;
				}
				if(a[i].y==a[i].c)
				{
					s2++;
					ans+=a[i].y;
				}
				else
				{
					s3++;
					ans+=a[i].z;
				}
			}
			else if(a[i].y==a[i].b)
			{
				if(s2<m)
				{
					s2++;
					ans+=a[i].y;
					continue;
				}
				if(a[i].x==a[i].c)
				{
					s1++;
					ans+=a[i].x;
				}
				else
				{
					s3++;
					ans+=a[i].z;
				}
			}
			else
			{
				if(s3<m)
				{
					s3++;
					ans+=a[i].z;
					continue;
				}
				if(a[i].x==a[i].c)
				{
					s1++;
					ans+=a[i].x;
				}
				else
				{
					s2++;
					ans+=a[i].y;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
