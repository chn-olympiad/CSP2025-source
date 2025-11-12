#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,cnt=0,ans=0;
struct node
{
	int a,b,c;
}s[N];
struct edge
{
	int id,d;	
}d[N];
bool cmp1(node x,node y)
{
	return x.a-x.b>y.a-y.b;
}
bool cmp2(edge x,edge y)
{
	return x.d>y.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		ans=0;cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		sort(s+1,s+1+n,cmp1);
	//	for(int i=1;i<=n;i++)cout<<s[i].a<<' '<<s[i].b<<' '<<s[i].c<<'\n';
		int a=0,b=0;
		for(int i=1;i<=n/2;i++)
		{a++;
			ans+=s[i].a;
			if(s[i].c>s[i].a)
			{
				d[++cnt].d=s[i].c-s[i].a;
				d[cnt].id=i;
			}
		}
		for(int i=n/2+1;i<=n;i++)
		{b++;
			ans+=s[i].b;
			if(s[i].c>s[i].b)
			{
				d[++cnt].d=s[i].c-s[i].b;
				d[cnt].id=i;
			}
		}
		sort(d+1,d+1+cnt,cmp2);
		int p[N]={};
		for(int i=1;i<=cnt&&i<=n/2;i++)
		{
			ans+=d[i].d;
			if(d[i].id<=n/2)a--;
			else b--;
			p[d[i].id]=1;
		}
		for(int i=1;i<=n/2;i++)
		{
			if(p[i]==0&&b<n/2)
			{
				if(s[i].b>s[i].a)
				{
					ans+=s[i].b-s[i].a;
					b++;
				}
			}
		}
		for(int i=n/2+1;i<=n;i++)
		{
			if(p[i]==0&&a<n/2)
			{
				if(s[i].a>s[i].b)
				{
					ans+=s[i].a-s[i].b;
					a++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
