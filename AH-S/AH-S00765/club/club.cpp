#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,y,z,m,mm,mmm,c1,c2,c3,ans;
struct node
{
	int b,c,d,e,f,g;
}a[100005];
bool cmp1(node x,node y)
{
	if(x.f==y.f)
	{
		return x.g<y.g;
	}
	return x.f<y.f;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		c1=c2=c3=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].b>>a[i].c>>a[i].d;
			x=a[i].b,y=a[i].c,z=a[i].d;
			m=max({x,y,z});
			ans+=m;
			if(m==x)
			{
				c1++;
				mm=max(y,z);
				if(mm==y)
				{
					a[i].e=1;
					mmm=z;
				}
				else
				{
					a[i].e=2;
					mmm=y;
				}
			}
			else if(m==y)
			{
				c2++;
				mm=max(x,z);
				if(mm==x)
				{
					a[i].e=3;
					mmm=z;
				}
				else
				{
					a[i].e=4;
					mmm=x;
				}
			}
			else
			{
				c3++;
				mm=max(x,y);
				if(mm==x)
				{
					a[i].e=5;
					mmm=y;
				}
				else
				{
					a[i].e=6;
					mmm=x;
				}
			}
			a[i].f=m-mm,a[i].g=mm-mmm;
		}
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(a[i].e>=1&&a[i].e<=2)
			{
				if(c1>n/2)
				{
					ans-=a[i].f;
					c1--;
				}
			}
			else if(a[i].e>=3&&a[i].e<=4)
			{
				if(c2>n/2)
				{
					ans-=a[i].f;
					c2--;
				}
			}
			else
			{
				if(c3>n/2)
				{
					ans-=a[i].f;
					c3--;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
