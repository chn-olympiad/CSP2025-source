#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,b=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a[3][10015];
		cin>>n;
		int d=n/2;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				for(int o=k;o<=3;o++)
				{
					if(a[k][j]<a[o][j])
					{
						int d=a[k][j];
						a[k][j]=a[o][j];
						a[o][j]=d;
					}
				}
			}
			b+=a[1][j];
		}
		cout<<b;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
