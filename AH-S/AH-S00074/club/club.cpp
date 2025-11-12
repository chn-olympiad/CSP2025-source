#include<bits/stdc++.h>
using namespace std;
int n[6],a[6][100001][4],bm[6][4],pd[6][100001],max1[6],pd2[6];
long long sum[6];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[i][j][k];
			}
		}
	}
	for(int i=1;i<=t;i++)
	{
		int jx=n[i]/2;
		while(pd2[i]!=n[i])
		{
			max1[i]=0;
			for(int j=1;j<=n[i];j++)
			{	
				for(int k=1;k<=3;k++)
				{
					if(a[i][j][k]>max1[i]&&bm[i][k]<jx&&pd[i][j]==0)
						max1[i]=a[i][j][k];
				}
			}
			if(max1[i]==0)
				break;
			for(int j=1;j<=n[i];j++)
			{
				for(int k=1;k<=3;k++)
				{
					if(a[i][j][k]==max1[i]&&bm[i][k]<jx&&pd[i][j]==0)
					{
						bm[i][k]++;
						pd[i][j]=1;
						sum[i]+=a[i][j][k];
						a[i][j][k]=0;
						pd2[i]++;
					}
				}
			}
		}
		cout<<sum[i]<<endl;
	}
	return 0;
}
