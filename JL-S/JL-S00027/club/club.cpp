#include <bits/stdc++.h>
using namespace std;
#define M 1005
int x[M][M];
int sum[M],p[M];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,cnt=0;
	cin>>t;
	for(int l=0;l<t;l++)
	{
		cin>>n;
		for(int k=0;k<M;k++)
		{
			sum[k]=0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>x[i][j];
				if(x[i][j]>sum[i])
				{
					sum[i]=x[i][j];
					
				}
			}
			 
		
	}
	for(int i=0;i<n;i++)
		{
			cnt+=sum[i];
		}
		cout<<cnt<<endl;
}
	return 0;
}
