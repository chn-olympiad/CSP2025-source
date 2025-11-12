#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
struct Node{
	ll c[4];
	ll ma,ma2,d,m1,m2;
}a[N];
bool cmp(Node a,Node b)
{
	if(a.d!=b.d)
	{
		return a.d>b.d;
	}
	return a.m1>b.m2;
}
ll n,m,t,ans,v[N],num,b[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].c[1]>>a[i].c[2]>>a[i].c[3];
			if(a[i].c[1]>=a[i].c[2]&&a[i].c[1]>=a[i].c[3])
			{
				a[i].ma=1;
				a[i].m1=a[i].c[a[i].ma];
			}
			else if(a[i].c[2]>=a[i].c[1]&&a[i].c[2]>=a[i].c[3])
			{
				a[i].ma=2;
				a[i].m1=a[i].c[a[i].ma];
			}
			else
			{
				a[i].ma=3;
				a[i].m1=a[i].c[a[i].ma];
			}
			if(a[i].c[1]<a[i].c[2]&&a[i].c[1]<a[i].c[3])
			{
				if(a[i].ma==3)
				{
					a[i].ma2=2;
					a[i].m2=a[i].c[a[i].ma2];
				}
				else
				{
					a[i].ma2=3;
					a[i].m2=a[i].c[a[i].ma2];
				}
			}
			else if(a[i].c[2]<a[i].c[1]&&a[i].c[2]<a[i].c[3])
			{
				if(a[i].ma==3)
				{
					a[i].ma2=1;
					a[i].m2=a[i].c[a[i].ma2];
				}
				else
				{
					a[i].ma2=3;
					a[i].m2=a[i].c[a[i].ma2];
				}
			}
			else
			{
				if(a[i].ma==1)
				{
					a[i].ma2=2;
					a[i].m2=a[i].c[a[i].ma2];
				}
				else
				{
					a[i].ma2=1;
					a[i].m2=a[i].c[a[i].ma2];
				}
			}
			a[i].d=a[i].m1-a[i].m2;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(b[a[i].ma]==n/2)
			{
				b[a[i].ma2]++;
				ans+=a[i].m2;
			}
			else
			{
				b[a[i].ma]++;
				ans+=a[i].m1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
