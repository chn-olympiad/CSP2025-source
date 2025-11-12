#include<bits/stdc++.h>
using namespace std;
struct club{
	int a1;
	int a2;
	int a3;
	int lp_;
}a[100005];
bool camp(club x,club y)
{
	return x.lp_>y.lp_;
}
int max_(club x)
{
	if(x.a1>x.a2)	
	{
		if(x.a1>x.a3)	return 1;
		return 3;
	}
	if(x.a2>x.a3)	return 2;
	return 3;
}
int mid(club x)
{
	if(x.a1>x.a2)	
	{
		if(x.a2>x.a3)	return 2;
		else
		{
			if(x.a1<x.a3)	return 1;
			return 3;	
		}
	}
	if(x.a1>x.a3)	return 1;
	if(x.a2<x.a3)	return 2;
	return 3;
}
int lp(club x)
{
	int t1,t2;
	if(max_(x)==1)	t1=x.a1;
	if(max_(x)==2)	t1=x.a2;
	if(max_(x)==3)	t1=x.a3;
	if(mid(x)==1)	t2=x.a1; 
	if(mid(x)==2)	t2=x.a2; 
	if(mid(x)==3)	t2=x.a3;
	return t1-t2;  
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int c1=0,c2=0,c3=0;
	int t,n,k,s;
	cin>>t;k=t;
	int ans[7];
	while(t--)
	{
		ans[t]=0;
		cin>>n;
		s=n/2;
		for(int i = 1 ; i<=n ;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].lp_=lp(a[i]);
		}
		sort(a+1,a+1+n,camp);
		for(int i = 1 ; i<=n ; i++)
		{
			if(max_(a[i])==1)	
			{
				if(c1<s)	{c1++;ans[t]+=a[i].a1;continue;}
				if(mid(a[i])==2)
				{
					c2++;
					ans[t]+=a[i].a2;
					continue;
				}	
					c3++;
					ans[t]+=a[i].a3;
					continue;
			}
			if(max_(a[i])==2)	
			{
				if(c2<s)	{c2++;ans[t]+=a[i].a2;continue;}
				if(mid(a[i])==1)
				{
					c1++;
					ans[t]+=a[i].a1;
					continue;
				}	
					c3++;
					ans[t]+=a[i].a3;
					continue;
			}
			if(max_(a[i])==3)	
			{
				if(c3<s)	{c3++;ans[t]+=a[i].a3;continue;}
				if(mid(a[i])==2)
				{
					c2++;
					ans[t]+=a[i].a2;
					continue;
				}	
					c1++;
					ans[t]+=a[i].a1;
					continue;
			}
		}
	}
	while(k--)
		cout<<ans[k];
	return 0;
}