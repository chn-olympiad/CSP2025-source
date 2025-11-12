#include <bits/stdc++.h>
using namespace std;
int n,t,a[100005],c[10005];
int h,sum=0;
int main()
{
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for (int k=1;k<=t;k++)
	{
		cin>>n;
		for (int i=1;i<=3;i++)
		{
			for (int j=i;j<=n;j++)
			{
				cin>>a[i];
				cin>>c[j];
			}
		}
		for (int i=1;i<=3;i++)
		{
			for (int j=i;j<=n;j++)
			{
				if (a[i]<=a[i+1])
				{
					sum+=a[i+1];
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

