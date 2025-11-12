#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,s,ln=0;
struct y
{
	int n=0;
	int p1=0;
	int p2=0;
	int p3=0;
	int out=0;
	int next_out=0;
}a[N];
bool cmp_1(y g,y b)
{
	return g.p1>b.p1;
}
bool cmp_2(y g,y b)
{
	return g.p2>b.p2;
}
bool cmp_3(y g,y b)
{
	return g.p3>b.p3;
}
void f(int k)
{
	if(a[k].p1>a[k].p2 && a[k].p1>a[k].p3)
	{
		a[k].out=1;
	}
	else if(a[k].p2 >a[k].p1 &&a[k].p2>a[k].p3)
	{
		a[k].out=2;
	}
	else if(a[k].p3 >a[k].p1 &&a[k].p3>a[k].p2)
	{
		a[k].out=3;
	}
	else if(a[k].p2 >a[k].p1 &&a[k].p2==a[k].p3)
	{
		a[k].out=2;
		a[k].next_out=3;
	}
	else if(a[k].p1 >a[k].p2 &&a[k].p1==a[k].p3)
	{
		a[k].out=1;
		a[k].next_out=3;
	}
	else if(a[k].p2 >a[k].p3 &&a[k].p2==a[k].p1)
	{
		a[k].out=2;
		a[k].next_out=1;
	}
	
}
int main()
{
	
	cin>>t;
	while(t--)
	{
		s=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].p1>>a[i].p2>>a[i].p3;
			a[i].n=i+1;
			f(i);
		}
		sort(a+0,a+n,cmp_1);
		int c=0;
		for(int i=ln;i<n;i++)
		{
			if(a[i].out==1)
			{
				c++;
				s+=a[i].p1;
				a[i].next_out=0;
				if(c>=n/2)
				{
					break;
				}
			}
		}
		sort(a+0,a+n,cmp_2);
		c=0;
		for(int i=ln;i<n;i++)
		{
			if(a[i].out==2)
			{
				c++;
				s+=a[i].p2;
				a[i].next_out=0;
				if(c>=n/2)
				{
					break;
				}
			}
		}
		sort(a+0,a+n,cmp_3);
		c=0;
		for(int i=ln;i<n;i++)
		{
			if(a[i].out==3)
			{
				c++;
				s+=a[i].p3;
				a[i].next_out=0;
				if(c>=n/2)
				{
					break;
				}
			}
		}
		cout<<s<<endl;	 
	}
	return 0;
}
