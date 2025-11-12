#include<bits/stdc++.h>
using namespace std;
int j;
long long s;
int n,s1,s2,s3;
struct st
{
	int n1,n2,n3;
	int t;
};
int co(int x,int y,int z)
{
	if(x>=y&&x>=z)return 1;
	if(y>=x&&y>=z)return 2;
	if(z>=x&&z>=y)return 3;
	else return 1;
}
bool co1(st x,st y)
{
	if(x.t!=y.t)return x.t<y.t;
	int xn12,xn13,yn12,yn13;
	xn12=x.n1-x.n2;
	xn13=x.n1-x.n3;
	yn12=y.n1-y.n2;
	yn13=y.n1-y.n3;
	return min(xn12,xn13)<min(yn12,yn13);
	
}
bool co2(st x,st y)
{
	if(x.t!=y.t)return abs(x.t-2)<abs(y.t-2);

	int xn23,xn21,yn23,yn21;
	xn23=x.n2-x.n3;
	xn21=x.n2-x.n1;
	yn23=y.n2-y.n3;
	yn21=y.n2-y.n1;
	return min(xn21,xn23)<min(yn21,yn23);
}
bool co3(st x,st y)
{
	if(x.t!=y.t)return abs(x.t-3)<abs(y.t-3);
	int xn31,xn32,yn31,yn32;
	xn31=x.n3-x.n1;
	xn32=x.n3-x.n2;
	yn31=y.n3-y.n1;
	yn32=y.n3-y.n2;
	return min(xn31,xn32)<min(yn31,yn32);

}
st a[100010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;s=0;s1=0;s2=0;s3=0;
		for(int i=0;i<n;i++)
		{
			a[i].n1=0;a[i].n2=0;a[i].n3=0;a[i].t=0;
		}
		for(int i=0;i<n;i++)
		{
			cin>>a[i].n1>>a[i].n2>>a[i].n3;
			int x=co(a[i].n1,a[i].n2,a[i].n3);
			if(x==1)
			{
				a[i].t=1;
				s1++;
			}
			if(x==2)
			{
				a[i].t=2;
				s2++;
			}
			if(x==3)
			{
				a[i].t=3;
				s3++;
			}
	
		}
	
		sort(a,a+n,co1);
		j=0;
		while(s1>n/2)
		{

			s1--;
			if(a[j].n2>a[j].n3)
			{
				a[j].t=2;
				s2++;
			}
			else 
			{
				a[j].t=3;
				s3++;
			}
			
			j++;
		}
		
		sort(a,a+n,co2);
		j=0;
		while(s2>n/2)
		{
			if(a[j].n1>a[j].n3)
			{
				a[j].t=1;
				s1++;
			}
			else 
			{
				a[j].t=3;
				s3++;
			}
			s2--;
			
			j++;
		}

		sort(a,a+n,co3);
		j=0;
		while(s3>n/2)
		{
			if(a[j].n2>a[j].n1)
			{
				a[j].t=2;
				s2++;
			}
			else 
			{
				a[j].t=1;
				s1++;
			}
			s3--;
			
			j++;
		}

		for(int i=0;i<n;i++)
		{
			
			if(a[i].t==1)s+=a[i].n1;
			else if(a[i].t==2)s+=a[i].n2;
			else if(a[i].t==3)s+=a[i].n3;
		}
		cout<<s<<"\n";
		
	}
	return 0;
}
