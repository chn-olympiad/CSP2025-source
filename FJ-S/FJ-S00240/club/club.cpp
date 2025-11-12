#include<iostream>
#include<algorithm>
using namespace std;
long long t,n,sum1,sum2,sum3,sum0,sum,c[100005],suma,sumb;
struct stu
{
	int c1,c2,c3,q1,q2,q3;
}a[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::cin>>t;
	for(int i=1;i<=t;i++)
	{
		std::cin>>n;
		long long sum1=0,sum2=0,sum3=0,sum0=n/2,sum=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j].c1>>a[j].c2>>a[j].c3;
			if(a[j].c2==0&&a[j].c3==0)
			{
				c[j]=a[j].c1;
				suma+=c[j];
			}
			if(a[j].c2==0&&a[j].c3==0&&j==n)
			{
				sort(c+1,c+n+1);
				for(int k=1;k<=n/2;k++)
					suma-=c[k];
				cout<<suma<<endl;
				return 0;
			}
			a[j].q1=max(a[j].c1,max(a[j].c2,a[j].c3));
			sum+=a[j].q1;
			if(a[j].q1==a[j].c1)
			{
				a[j].q2=max(a[j].c2,a[j].c3);
				a[j].q1=1;
				if(a[j].q2==a[j].c2)
				{
					a[j].q3=3;
					a[j].q2=2;
				}
				else if(a[j].q2==a[j].c3)
				{
					a[j].q2=3;
					a[j].q3=2;
				}
				sum1++;
			}
			if(a[j].q1==a[j].c2)
			{
				a[j].q2=max(a[j].c1,a[j].c3);
				a[j].q1=2;
				if(a[j].q2==a[j].c1)
				{
					a[j].q3=3;
					a[j].q2=1;
				}
				else if(a[j].q2==a[j].c3)
				{
					a[j].q2=3;
					a[j].q3=1;
				}
				sum2++;
			}
			if(a[j].q1==a[j].c3)
			{
				a[j].q2=max(a[j].c2,a[j].c1);
				a[j].q1=3;
				if(a[j].q2==a[j].c1)
				{
					a[j].q3=2;
					a[j].q2=1;
				}
				else if(a[j].q2==a[j].c2)
				{
					a[j].q2=2;
					a[j].q3=1;
				}
				sum3++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
