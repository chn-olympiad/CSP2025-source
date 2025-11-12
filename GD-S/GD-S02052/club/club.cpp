#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+5;
ll t;
ll n;
struct abc
{
	ll one,two,three;
}a[N];
struct hu
{
	ll id,zhu,ci;
}on[N];
struct zhi
{
	ll id,zhu,ci;
}tw[N];
struct hui
{
	ll id,zhu,ci;
}th[N];
ll p1,p2,p3;
ll sum;
bool cmp1(hu x,hu y)
{
	return (x.zhu-x.ci)>(y.zhu-y.ci);
}
bool cmp2(zhi x,zhi y)
{
	return (x.zhu-x.ci)>(y.zhu-y.ci);
}
bool cmp3(hui x,hui y)
{
	return (x.zhu-x.ci)>(y.zhu-y.ci);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].one>>a[i].two>>a[i].three;
			if(a[i].one>=a[i].two&&a[i].one>=a[i].three)
			{
				on[++p1].id=i,on[p1].zhu=a[i].one;
				if(a[i].three<a[i].two)on[p1].ci=a[i].two;
				else on[p1].ci=a[i].three;
			}
			else if(a[i].two>=a[i].three&&a[i].two>=a[i].one)
			{
				tw[++p2].id=i,tw[p2].zhu=a[i].two;
				if(a[i].three<a[i].one)tw[p2].ci=a[i].one;
				else tw[p2].ci=a[i].three;
			}
			else
			{
				th[++p3].id=i,th[p3].zhu=a[i].three;
				if(a[i].two<a[i].one)th[p3].ci=a[i].one;
				else th[p3].ci=a[i].two;
			}
		}
		sort(on+1,on+1+p1,cmp1);
		sort(tw+1,tw+1+p2,cmp2);
		sort(th+1,th+1+p3,cmp3);
		if(p1<=n/2)
		{
			for(int i=1;i<=p1;i++)
			{
				sum+=on[i].zhu;
			}
		}
		else
		{
			for(int i=1;i<=p1;i++)
			{
				if(i<=n/2)sum+=on[i].zhu;
				else sum+=on[i].ci;
			}
		}
		if(p2<=n/2)
		{
			for(int i=1;i<=p2;i++)
			{
				sum+=tw[i].zhu;
			}
		}
		else
		{
			for(int i=1;i<=p2;i++)
			{
				if(i<=n/2)sum+=tw[i].zhu;
				else sum+=tw[i].ci;
			}
		}
		if(p3<=n/2)
		{
			for(int i=1;i<=p3;i++)
			{
				sum+=th[i].zhu;
			}
		}
		else
		{
			for(int i=1;i<=p3;i++)
			{
				if(i<=n/2)sum+=th[i].zhu;
				else sum+=th[i].ci;
			}
		}
		//cout<<p1<<" "<<p2<<" "<<p3;
		cout<<sum<<"\n";
		sum=0;
		p1=0,p2=0,p3=0;
	}
	
	
	return 0;
} 
