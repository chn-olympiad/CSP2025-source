#include<bits/stdc++.h>
using namespace std;
struct stu{
	int a,b,c;
};
bool cmp1(stu& a,stu& b)
{
	return min(a.a-a.b,a.a-a.c)>min(b.a-b.b,b.a-b.c);
}
bool cmp2(stu& a,stu& b)
{
	return min(a.b-a.a,a.b-a.c)>min(b.b-b.a,b.b-b.c);
}
bool cmp3(stu& a,stu& b)
{
	return min(a.c-a.a,a.c-a.b)>min(b.c-b.a,b.c-b.b);
}
void solve()
{
	int n;cin>>n;
	vector<stu> a,b,c;
	int aa,bb,cc;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>aa>>bb>>cc;
		if(aa>=bb&&aa>=cc)
		{
			a.push_back({aa,bb,cc});
			ans+=aa;
		}
		else if(bb>=aa&&bb>=cc)
		{
			b.push_back({aa,bb,cc});
			ans+=bb;
		}
		else
		{
			c.push_back({aa,bb,cc});
			ans+=cc;
		}
	}
	if(a.size()>n/2)
	{
		sort(a.begin(),a.end(),cmp1);
		while(a.size()>n/2)
		{
			if(b.size()<=n/2&&a[a.size()-1].b>=a[a.size()-1].c)
			{
				ans-=a[a.size()-1].a;
				ans+=a[a.size()-1].b;
				b.push_back({0,0,0});
			}
			else
			{
				ans-=a[a.size()-1].a;
				ans+=a[a.size()-1].c;
				c.push_back({0,0,0});
			}
			a.pop_back();
		}
	}
	else if(b.size()>n/2)
	{
		sort(b.begin(),b.end(),cmp2);
		while(b.size()>n/2)
		{
			if(a.size()<=n/2&&b[b.size()-1].a>=b[b.size()-1].c)
			{
				ans-=b[b.size()-1].b;
				ans+=b[b.size()-1].a;
				a.push_back({0,0,0});
			}
			else
			{
				ans-=b[b.size()-1].b;
				ans+=b[b.size()-1].c;
				c.push_back({0,0,0});
			}
			b.pop_back();
		}
	}
	else
	{
		sort(c.begin(),c.end(),cmp3);
		while(c.size()>n/2)
		{
			if(a.size()<=n/2&&c[c.size()-1].a>=c[c.size()-1].b)
			{
				ans-=c[c.size()-1].c;
				ans+=c[c.size()-1].a;
				a.push_back({0,0,0});
			}
			else
			{
				ans-=c[c.size()-1].c;
				ans+=c[c.size()-1].b;
				b.push_back({0,0,0});
			}
			c.pop_back();
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
