#include<bits/stdc++.h>
using namespace std;
struct yg{
	int a,b,c,cha,bm=0;
}a[100005];
int t,n,ans=0,b1=0,b2=0,b3=0,pd;
bool cmp(yg a1,yg a2)
{
	if(a1.bm==pd&&a2.bm==pd)return a1.cha<=a2.cha;
	return a1.bm==pd;
}
void px(int s,int v)
{
	int r=s-v;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=r;i++)
	{
		ans-=a[i].cha;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		b1=b2=b3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
			{
				ans+=a[i].a;
				b1++;
				a[i].bm=1;
				a[i].cha=a[i].a-max(a[i].b,a[i].c);
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
			{
				ans+=a[i].b;
				b2++;
				a[i].bm=2;
				a[i].cha=a[i].b-max(a[i].a,a[i].c);
			}
			else
			{
				ans+=a[i].c;
				b3++;
				a[i].bm=3;
				a[i].cha=a[i].c-max(a[i].a,a[i].b);
			}
		}
		if(b1<=n/2&&b2<=n/2&&b3<=n/2)cout<<ans<<"\n";
		else
		{
			if(b1>n/2)
			{
				pd=1;
				px(b1,n/2);
			}
			else if(b2>n/2)
			{
				pd=2;
				px(b2,n/2);
			}
			else
			{
				pd=3;
				px(b3,n/2);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}