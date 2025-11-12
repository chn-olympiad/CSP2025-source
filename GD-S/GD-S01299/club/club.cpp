#include<bits/stdc++.h>
using namespace std;
long long n,T;
struct cj{
	long long o,t,th;
}a[100005];
bool cp1(cj a,cj b)
{
	if(a.o>b.o)
		return a.o>b.o;
	if(a.t+a.th>b.t+b.th)
		return a.t+a.th>b.t+b.th;
}
bool cp2(cj a,cj b)
{
	if(a.t>b.t)
		return a.t>b.t;
	if(a.o+a.th>b.o+b.th)
		return a.o+a.th>b.o+b.th;
}
bool cp3(cj a,cj b)
{
	if(a.th>b.th)
		return a.th>b.th;
	if(a.t+a.o>b.t+b.o)
		return a.t+a.o>b.t+b.o;
}
long long yucl(long long ji)
{
	if(ji==1)
		sort(a+1,a+n+1,cp1);
	if(ji==2)
		sort(a+1,a+n+1,cp2);
	if(ji==3)
		sort(a+1,a+n+1,cp3);
	long long js[5]={0},ans=0;
	for(int i=1;i<=n;i++)
	{
		long long ma=-1,mi;
		if(ma<a[i].o)
		{
			ma=a[i].o;
			mi=1;
		}
		if(ma<a[i].t)
		{
			ma=a[i].t;
			mi=2;
		}
		if(ma<a[i].th)
		{
			ma=a[i].th;
			mi=3;
		}
		if(js[mi]<n/2)
		{
			js[mi]++;
			ans+=ma;
		}
		else
		{
			if(a[i].o==ma)
				ans+=max(a[i].t,a[i].th);
			if(a[i].t==ma)
				ans+=max(a[i].o,a[i].th);
			if(a[i].th==ma)
				ans+=max(a[i].t,a[i].o);
		}
	}
	return ans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].o>>a[i].t>>a[i].th;
		long long ans=max(max(yucl(1),yucl(2)),yucl(3));
		cout<<ans<<endl;
	}
	return 0;
}
