#include<bits/stdc++.h>
using namespace std;
int t,n;
struct per
{
	int a,b,c,f,s,l;
}p[100010];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q,qbu,qbz;
void se(int i)
{
	if(p[i].a>=p[i].b)
	{
		if(p[i].b>=p[i].c) p[i].f=1,p[i].s=2,p[i].l=3;
		else
		{
			if(p[i].a>=p[i].c) p[i].f=1,p[i].s=3,p[i].l=2;
			else p[i].f=3,p[i].s=1,p[i].l=2;
		}
	}
	else
	{
		if(p[i].a>=p[i].c) p[i].f=2,p[i].s=1,p[i].l=3;
		else
		{
			if(p[i].b>=p[i].c) p[i].f=2,p[i].s=3,p[i].l=1;
			else p[i].f=3,p[i].s=2,p[i].l=1;
		}
	}
}
bool cmp(per a,per b)
{
	return a.a>b.a;
}
bool cmp2(per a,per b) 
{
	return a.b>b.b;
}
bool cmp3(per a,per b)
{
	return a.c>b.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
			se(i);
		}
		int sum=0;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n/2;i++) sum+=p[i].a;
		sort(p+1,p+n+1,cmp2);
		for(int i=1;i<=n/2;i++) sum+=p[i].b;
		sort(p+1,p+n+1,cmp3);
		for(int i=1;i<=n/2;i++) sum+=p[i].c;
		cout<<sum;
	}
	return 0;
}
