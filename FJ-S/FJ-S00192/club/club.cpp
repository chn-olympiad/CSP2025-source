#include <bits/stdc++.h>
using namespace std;
struct jgt{//定义结构体 
	int a1,a2,a3,maxn,max2,max3,pos;
	bool f;
};
jgt a[100010]; 
int t,n,num[4],sum,j;
long long st[10010];
bool cmp(jgt x,jgt y)
{
	if(x.maxn > y.maxn) return x.maxn > y.maxn;
	if(x.maxn < y.maxn) return x.maxn < y.maxn;
	if (x.maxn == y.maxn)
	{
		if(x.max2 > y.max2) return x.maxn> y.maxn;
		if(x.max2 < y.max2) return x.maxn< y.maxn;
		if (x.max2 == y.max2)
		{
			if(x.max3 > y.max3) return x.maxn> y.maxn;
			if(x.max3 < y.max3) return x.maxn < y.maxn;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		sum=0,num[1]=0,num[2]=0,num[3]=0;
		for (int i=1;i<=n;i++)
		{
			a[i].f=false;
		}
		for (int i=1;i<=n;i++)
		{
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			if (a[i].a1>a[i].a2 && !a[i].f)
			{
				if (a[i].a1 > a[i].a3)
				{
					a[i].maxn=a[i].a1;
					if (a[i].a2>a[i].a3)
					{
						a[i].max2=a[i].a2;
						a[i].max3=a[i].a3;
					}
					
					else {
						a[i].max2=a[i].a3;
						a[i].max3=a[i].a2;
					}
					a[i].pos=1;
					a[i].a1=0;
				}
				else
				{
					a[i].maxn=a[i].a3;
					a[i].max2=a[i].a1;
					a[i].max3=a[i].a2;
					a[i].pos=3;
					a[i].a3=0;
				}
			}
			else if (a[i].a1<a[i].a2 && !a[i].f)
			{
				if (a[i].a2 > a[i].a3)
				{
					if (a[i].a1>a[i].a3)
					{
						a[i].max2=a[i].a1;
						a[i].max3=a[i].a3;
					}
					else {
						a[i].max2=a[i].a3;
						a[i].max3=a[i].a1;
					}
					a[i].maxn=a[i].a2;
					a[i].pos=2;
					a[i].a2=0;
				}
				else
				{
					a[i].max2=a[i].a2;
					a[i].max3=a[i].a1;
					a[i].maxn=a[i].a3;
					a[i].pos=3;
					a[i].a3=0;
				}	
			}	
		}
		
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			if (num[a[i].pos]<n/2&& !a[i].f)
			{
				sum+=a[i].maxn;
				num[a[i].pos]++;
				a[i].f=true;
			}
			if (a[i].a1>a[i].a2 && !a[i].f)
			{
				if (a[i].a1 > a[i].a3)
				{
					a[i].maxn=a[i].a1;
					if (a[i].a2>a[i].a3)
					{
						a[i].max2=a[i].a2;
						a[i].max3=a[i].a3;
					}
					
					else {
						a[i].max2=a[i].a3;
						a[i].max3=a[i].a2;
					}
					a[i].pos=1;
					a[i].a1=0;
				}
				else
				{
					a[i].maxn=a[i].a3;
					a[i].max2=a[i].a1;
					a[i].max3=a[i].a2;
					a[i].pos=3;
					a[i].a3=0;
				}
			}
			else if (a[i].a1<a[i].a2 && !a[i].f)
			{
				if (a[i].a2 > a[i].a3)
				{
					if (a[i].a1>a[i].a3)
					{
						a[i].max2=a[i].a1;
						a[i].max3=a[i].a3;
					}
					else {
						a[i].max2=a[i].a3;
						a[i].max3=a[i].a1;
					}
					a[i].maxn=a[i].a2;
					a[i].pos=2;
					a[i].a2=0;
				}
				else
				{
					a[i].max2=a[i].a2;
					a[i].max3=a[i].a1;
					a[i].maxn=a[i].a3;
					a[i].pos=3;
					a[i].a3=0;
				}	
			}	
		}
		
		sort(a+1,a+n+1,cmp);
		for (int i=1;i<=n;i++)
		{
			if (num[a[i].pos]<n/2&& a[i].f==false)
			{
				sum+=a[i].maxn;
				num[a[i].pos]++;
			}
			if(a[i].a1!=0 && !a[i].f && num[a[i].pos]<n/2) sum+=a[i].a1;
			if(a[i].a2!=0 && !a[i].f && num[a[i].pos]<n/2) sum+=a[i].a2;
			if(a[i].a3!=0 && !a[i].f && num[a[i].pos]<n/2) sum+=a[i].a3;
			
		}
		cout << sum << endl;
	}
	
}
