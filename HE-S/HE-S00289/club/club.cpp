#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100010],vis1[100010],ans[4][100010],w,df,qw,er[4][100010],sum=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	int a1,a2,a3;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		a1=0;a2=0;a3=0;
		cin>>n;
		sum=0;
		for(int j=1;j<=n;j++)
		{
			
			vis1[j]=0;
			cin>>a[1][j]>>a[2][j]>>a[3][j];
		}
		for(int j=1;j<=n;j++)
		{
			if(a[1][j]>=a[2][j]&&a[1][j]>=a[3][j]&&vis1[j]!=1&&a1<n/2)
			{
				a1++;
				sum+=a[1][j];
				vis1[j]=1;
			}
			else if(a[1][j]<=a[2][j]&&a[2][j]>=a[3][j]&&vis1[j]!=1&&a2<n/2)
			{
				a2++;
				sum+=a[2][j];
				vis1[j]=1;
			}
			else if(a[1][j]<=a[3][j]&&a[2][j]<=a[3][j]&&vis1[j]!=1&&a3<n/2)
			{
				a3++;
				sum+=a[3][j];
				vis1[j]=1;
			}
			else if(a1>=n/2)
			{
				if(a[2][j]>a[3][j])
				{
					sum+=a[2][j];
				}
				else sum+a[3][j];
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
