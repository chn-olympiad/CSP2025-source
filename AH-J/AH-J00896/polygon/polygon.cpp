#include<bits/stdc++.h>
using namespace std;
int n,mx=-1,sum,cnt;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		mx=max(a[i],mx);
	}
	if(n<3)
	{
		cout<<0;
	}
	if(n==3)
	{
		if(sum>2*mx)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		sort(a+1,a+n+1);
		sum=0; mx=0;
		int k;
		for(int i=1;i<=n-2;i++)
		{
			sum+=a[i];
			for(int j=i+1;j<=n-1;j++)
			{
				k=j+1;
				sum+=a[j];
				mx=a[j];
				sum+=a[k];
				while(k<=n)
				{
					k++;
					sum-=a[k-1];
					sum+=a[k];
					if(sum<=a[k]*2)
					{
						break;
					}
					else
					{
						cnt++;
						//printf("%d: %d %d %d\n",cnt,a[i],a[j],a[k]);
						
					}
				}
				sum-=a[j];
			}
			sum-=a[i];
		}
			
	}
	return 0;
}
