#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,ans,p1,p2,p3,a[100005],b[100005],c[100005];
struct node
{
	ll x,y,z;
}s[100005];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		p1=0;
		p2=0;
		p3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].x>>s[i].y>>s[i].z;
		}
		for(int i=1;i<=n;i++)
		{
			int u=max(s[i].x,max(s[i].y,s[i].z));
			ans+=u;
			if(u==s[i].x)
			{
				p1++;
				a[p1]=min(u-s[i].y,u-s[i].z);
			}
			else if(u==s[i].y)
			{
				p2++;
				b[p2]=min(u-s[i].x,u-s[i].z);
			}
			else
			{
				p3++;
				c[p3]=min(u-s[i].x,u-s[i].y);
			}
		}
		sort(a+1,a+p1+1);
		sort(b+1,b+p2+1);
		sort(c+1,c+p3+1);
		if(p1>n/2)
		{
			for(int i=1;i<=p1-n/2;i++)
			{
				ans-=a[i];
			}
		}
		else if(p2>n/2)
		{
			for(int i=1;i<=p2-n/2;i++)
			{
				ans-=b[i];
			}
		}
		else if(p3>n/2)
		{
			for(int i=1;i<=p3-n/2;i++)
			{
				ans-=c[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
