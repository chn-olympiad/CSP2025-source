#include<bits/stdc++.h>
using namespace std;
struct T
{
	int a,b,c,f;
	int ga,gb,gc;
}a[100007];
bool cmp1(T x,T y)
{
	return x.a>y.a;
}
bool cmp2(T x,T y)
{
	return x.b>y.b;
}
bool cmp3(T x,T y)
{
	return x.c>y.c;
}
bool cmp4(T x,T y)
{
	
	if(x.ga==y.ga)
		return x.a>y.a;
	return x.ga>y.ga;
}
bool cmp5(T x,T y)
{
	
	if(x.gb==y.gb)
		return x.b>y.b;
	return x.gb>y.gb;
}
bool cmp6(T x,T y)
{
	
	if(x.gc==y.gc)
		return x.c>y.c;
	return x.gc>y.gc;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		long long n,num1=0,num2=0,num3=0,sum=0,yuy=1,yu;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)
			a[i].ga=a[i].a-a[i+1].a;
		a[n].ga=0;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)
			a[i].gb=a[i].b-a[i+1].b;
		a[n].gb=0;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++)
			a[i].gc=a[i].c-a[i+1].c;
		a[n].gc=0;
		sort(a+1,a+n+1,cmp4);
		for(int i=1;i<=n;i++)
		{
			if(a[i].ga>a[i].gb&&a[i].ga>a[i].gc&&num1<n/2)
			{
				sum+=a[i].a;
				
				num1++;
				a[i].a=0;
				a[i].b=0;
				a[i].c=0;
				a[i].ga=-1;
				a[i].gc=-1;
				a[i].gb=-1;
			}
		}
		sort(a+1,a+n+1,cmp5);
		for(int i=1;i<=n;i++)
		{
			if(a[i].gb>a[i].ga&&a[i].gb>a[i].gc&&num2<n/2)
			{
				sum+=a[i].b;
				num2++;
				a[i].a=0;
				a[i].b=0;
				a[i].c=0;
				a[i].ga=-1;
				a[i].gc=-1;
				a[i].gb=-1;
			}
		}
		sort(a+1,a+n+1,cmp6);
		for(int i=1;i<=n;i++)
		{
			if(a[i].gc>a[i].gb&&a[i].gc>a[i].ga&&num3<n/2)
			{
				sum+=a[i].c;
				num3++;
				a[i].a=0;
				a[i].b=0;
				a[i].c=0;
				a[i].ga=-1;
				a[i].gc=-1;
				a[i].gb=-1;
			}
		}
		while(yuy)
		{
			yuy=0;
			for(int i=1;i<=n;i++)
			{
				int oq=0;
				if(a[i].ga>a[i].gb&&a[i].ga>a[i].gc&&num1<n/2)
					oq=1,num1++,sum+=a[i].a;
				if(a[i].gb>a[i].ga&&a[i].gb>a[i].gc&&num2<n/2)
					oq=1,num2++,sum+=a[i].b;
				if(a[i].gc>a[i].gb&&a[i].gc>a[i].ga&&num3<n/2)
					oq=1,num3++,sum+=a[i].c;
				if(oq)
				{
					a[i].a=0;
					a[i].b=0;
					a[i].c=0;
				}
				if(num1==n/2)
				{
					for(int j=i;j<=n;j++)
						a[j].ga=-1,a[j].a=0;
				}
				if(num2==n/2)
				{
					for(int j=i;j<=n;j++)
						a[j].gb=-1,a[j].b=0;
				}
				if(num3==n/2)
					for(int j=i;j<=n;j++)
						a[j].gc=-1,a[j].c=0;
			}
			for(int i=1;i<=n;i++)
			{
				if(a[i].a!=0||a[i].b!=0||a[i].c!=0)
				{
					if(yu==i)
					{
						sum+=max(max(a[i].a,a[i].b),a[i].c);
						break;
					}
					yu=i;
					yuy=1;
					break;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
