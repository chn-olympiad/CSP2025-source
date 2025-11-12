#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,a,b,c;
struct da
{
	int a,b,c;
}s[100010];
int a1[100010],a2[100010],a3[100010];
bool cmp(da a,da b)
{
	return abs(max(a.a,max(a.b,a.c))-(a.a+a.b+a.c)/3)<abs(max(b.a,max(b.b,b.c))-(b.a+b.b+b.c)/3);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n;
		ans=a=b=c=0;
		for (int i=0;i<n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if (max(s[i].a,max(s[i].b,s[i].c))==s[i].a)
			{
				ans+=s[i].a;
				a1[a++]=max(s[i].b,s[i].c)-s[i].a;
			}
			else if (s[i].b>s[i].c)
			{
				ans+=s[i].b;
				a2[b++]=max(s[i].a,s[i].c)-s[i].b;
			}
			else
			{
				ans+=s[i].c;
				a3[c++]=max(s[i].b,s[i].a)-s[i].c;
			}
		}
		if (a>n/2)
		{
			sort(a1,a1+a);
			for (int i=n/2;i<a;i++) ans+=a1[i];
		}
		if (b>n/2)
		{
			sort(a2,a2+b);
			for (int i=n/2;i<b;i++) ans+=a2[i];
		}
		if (c>n/2)
		{
			sort(a3,a3+c);
			for (int i=n/2;i<c;i++) ans+=a3[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}

