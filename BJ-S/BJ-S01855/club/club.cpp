#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		int ren[n][3];
		for(int k=0;k<n;k++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>ren[k][j];
			}
		}
		int sum=0;
		for(int k=0;k<n;k++)
		{
			if(ren[k][0]>=ren[k][1]&&ren[k][0]>=ren[k][2])
			{
				sum+=ren[k][0];
			}
			if(ren[k][1]>=ren[k][0]&&ren[k][1]>=ren[k][2])
			{
				sum+=ren[k][1];
			}
			if(ren[k][2]>=ren[k][1]&&ren[k][2]>=ren[k][0])
			{
				sum+=ren[k][2];
			}
		}
		cout<<sum;
	}
	return 0;
}