#include <bits/stdc++.h>
using namespace std;
int t,n;
struct P
{
	int a,b,c;
}s[100005];
bool cmp1(P x,P y)
{
	if (x.a==y.a)
	{
		return x.b<y.b;
	}
	return x.a>y.a;
}
bool cmp2(P x,P y)
{
	if (x.b==y.b)
	{
		return x.a<y.a;
	}
	return x.b>y.b;
}
void dfs()
{
	sort(s+1,s+n+1,cmp1);
	long long ans=0;
	for (int i=1;i<=n/2;i++)
	{
		ans+=1ll*s[i].a;
	}
	cout<<ans;
}
void dfsx()
{
	long long saz=0,sbz=0;
	for (int i=1;i<=n;i++)
	{
		saz+=1ll*s[i].a;
		sbz+=1ll*s[i].b;
	}
	
	sort(s+1,s+n+1,cmp1);
	long long sa=0;
	long long sb_=0;
	for (int i=1;i<=n/2;i++)
	{
		sa+=1ll*s[i].a;
		sb_+=1ll*s[i].b;
	}
	
	sort(s+1,s+n+1,cmp2);
	long long sb=0;
	long long sa_=0;
	for (int i=1;i<=n/2;i++)
	{
		sb+=1ll*s[i].b;
		sa_+=1ll*s[i].a;
	}
	
	if (sa+sbz-sb_>sb+saz-sa_)
	{
		cout<<sa+sbz-sb_;
	}
	else
	{
		cout<<sb+saz-sa_;
	}
}
void dfsxx()
{
	int r=max(s[1].a+s[2].b,s[1].a+s[2].c);
	int p=max(s[1].b+s[2].a,s[1].b+s[2].c);
	int q=max(s[1].c+s[2].a,s[1].c+s[2].b);
	cout<<max(r,max(p,q));
}
void dfsxxx()
{
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		int k=max(s[i].a,max(s[i].b,s[i].c));
		ans+=1ll*k;
	}
	cout<<ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n;
		bool x=true,y=true;
		for (int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if (s[i].b!=0)
			{
				x=false;
			}
			if (s[i].c!=0)
			{
				y=false;
			}
		}
		if (x && y)
		{
			dfs();
			continue;
		}
		if (y)
		{
			dfsx();
			continue;
		}
		if (n==2)
		{
			dfsxx();
			continue;
		}
		dfsxxx();
	}
	return 0;
}
