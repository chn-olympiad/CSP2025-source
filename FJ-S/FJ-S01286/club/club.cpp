#include<bits/stdc++.h>
using namespace std;
const int N=2e4+19; 
int main()
{
	int a[105][105],b[105],c[105],sum=0,d[105],e[105],num=0,o=0,s=0,h=0;
	int t;
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		h=0;
		s=0;
		o=0;
		num=0;
		sum=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		int n;
		cin>>n;
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		for (int g=1;g<=n;g++)
		{
			for (int q=1;q<=3;q++)
			{
				if (a[g][q]>b[g])
				{
					b[g]=a[g][q];
					c[q]+=1;
					d[g]=c[q];
				}
			}
			for (int e=1;e<=3;e++)
			{
				if (a[g][e]==b[g])
				{
					a[g][e]=0;
				}
			}
		}
		for (int k=1;k<=3;k++)
		{
			if (c[k]>n/2)
			{
				s=k;
				o=c[k]-n/2;
				num=1;
			}
		}
		if (num==1)
		{
			for (int w=1;w<=o;w++)
			{
				for (int q=1;q<=n;q++)
				{
					if (d[q]==s)
					{
						for (int j=1;j<=3;j++)
						{
							if (a[q][j]>h)
							{
								h=a[q][j];
							}
						}
						b[q]=h;
						}
					}
				}
			
			}
		}

		for (int q=1;q<=n;q++)
		{
			sum+=b[q];
		}
		cout<<sum;
	}
	return 0;
}
