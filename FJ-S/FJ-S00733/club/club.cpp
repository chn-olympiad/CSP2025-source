#include<bits/stdc++.h>
using namespace std;
struct ren{
	int du1,du2,du3;
	int maxdu,maxdu2,maxnum,maxnum2;
};
ren a[100005];
int b[4];
int c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		for(int i=1;i<=100005;i++)
		{
			a[i].du1=0;
			a[i].du2=0;
			a[i].du3=0;
			a[i].maxdu=0;
			a[i].maxdu2=0;
			a[i].maxnum=0;
			a[i].maxnum2=0;
			c[i]=0;
		}
		for(int i=1;i<=4;i++)
		{
			b[i]=0;
		}
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].du1>>a[i].du2>>a[i].du3;
			if(a[i].du1>=a[i].du2)
			{
				if(a[i].du1>=a[i].du3)
				{
					b[1]++;
					a[i].maxdu=a[i].du1;
					a[i].maxnum=1;
					if(a[i].du2>=a[i].du3)
					{
						a[i].maxdu2=a[i].du2;
						a[i].maxnum2=2;
					}
					else
					{
						a[i].maxdu2=a[i].du3;
						a[i].maxnum2=3;
					}
				}
				else
				{
					b[3]++;
					a[i].maxdu=a[i].du3;
					a[i].maxnum=3;
					a[i].maxdu2=a[i].du1;
				}
			}
			else
			{
				if(a[i].du2>=a[i].du3)
				{
					b[2]++;
					a[i].maxdu=a[i].du2;
					a[i].maxnum=2;
					if(a[i].du1>=a[i].du3)
					{
						a[i].maxdu2=a[i].du1;
						a[i].maxnum2=1;
					}
					else
					{
						a[i].maxdu2=a[i].du3;
						a[i].maxnum2=3;
					}
				}
				else
				{
					b[3]++;
					a[i].maxdu=a[i].du3;
					a[i].maxnum=3;
					a[i].maxdu2=a[i].du2;
				}
			}
		}
		if(b[1]<=n/2&&b[2]<=n/2&&b[3]<=n/2)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				sum+=a[i].maxdu; 
			}
			cout<<sum<<endl;
			continue;
		}
		int x=1;
		if(b[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].maxnum==1)
				{
					c[x]=a[i].maxdu-a[i].maxdu2;
					x++;
				}
			}
		}
		else if(b[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].maxnum==2)
				{
					c[x]=a[i].maxdu-a[i].maxdu2;
					x++;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].maxnum==3)
				{
					c[x]=a[i].maxdu-a[i].maxdu2;
					x++;
				}
			}
		}
		sort(c+1,c+x);
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++)
		{
			sum1+=a[i].maxdu; 
		}
		for(int i=1;i<=max(b[1],max(b[2],b[3]))-n/2;i++)
		{
			sum2+=c[i];
		}
		cout<<sum1-sum2<<endl;
	}
	return 0;
}

