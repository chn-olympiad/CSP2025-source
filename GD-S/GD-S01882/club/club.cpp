#include <bits/stdc++.h>
using namespace std;

int a[9999999][999999];
int sum;
int cnt[100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		sum=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
			int max=-100;
			int zu=0;
			bool f=1;
			for(int l=1;l<=3;l++)
			{
				if(a[j][l]>max)
				{
					zu=l;
					cnt[zu]++;
					
						max=a[j][l];
				}
					
			}
			sum+=max;
		//	cout<<sum[zu]<<' ';
		}
		cout<<sum<<endl;
	}
	//cout<<sum[1]<<endl;
	//cout<<sum[2]<<endl;
	//cout<<sum[3]<<endl;
	return 0;
 } 
