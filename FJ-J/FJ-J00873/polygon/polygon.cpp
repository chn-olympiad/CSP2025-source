#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int m=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)
		{
			sum=1;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int l=j+1;l<=n;l++)
				{
					if(a[i]+a[j]+a[l]>max(a[i],max(a[j],a[l]))*2)
					{
						sum++;
						sum=sum%m;
					}
					int p=a[i]+a[j]+a[l],maxx=max(a[j],max(a[i],a[l]));
					for(int l1=l+1;l1<=n;l1++)
					{
						if(p+a[l1]>max(maxx,a[l1])*2)
						{
							sum++;
						}
						int p1=p+a[l1],maxx1=max(maxx,a[l1]);
						for(int l2=l1+1;l2<=n;l2++)
						{
							if(p1+a[l2]>max(maxx1,a[l2])*2)
							{
								sum++;
							}
							int p2=p1+a[l2],maxx2=max(maxx1,a[l2]);
							for(int l3=l2+1;l3<=n;l3++)
							{
								if(p2+a[l3]>max(maxx1,a[l2])*2)
								{
									sum++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
