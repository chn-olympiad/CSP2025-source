#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,m,cnt=0;
	int a[5010]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]>=a[j]&&a[i]>=a[k])
				{
					m=a[i];
				}else if(a[j]>=a[i]&&a[j]>=a[k])
				{
					m=a[j];
				}else if(a[k]>=a[i]&&a[k]>=a[j])
				{
					m=a[k];
				}
				if(a[i]+a[j]+a[k]>m*2)
				{
					cnt+=1;
				}
			}
		}
	}
	cout<<cnt;
		
					
	fclose(stdin);
	fclose(stdout);
	return 0;
}
