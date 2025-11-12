#include<iostream>
#include<bits/stdc++.h>
using namespace std;	
int main()
{
	long long int bumen[100][100][100],t,n[100],max;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		for(int m=1;m<=n[i];m++)
		{
			for(int j=1;j<=3;j++)
			{
			cin>>bumen[i][m][j];
	       
			}
	
		}
	}
		long long int sum[t+1];
	for(int i=1;i<=t;i++)
	sum[i]=0;
    max=0;
	for(int i=1;i<=t;i++)
	{
		for(int m=1;m<=n[i];m++)
		{
			for(int j=1;j<=3;j++)
			{
				
			if(bumen[i][m][j]>=max)
			{
				max=bumen[i][m][j];
			}
	      
			}
	    sum[i]=sum[i]+max;max=0;
		}
	}
	 

for(int i=1;i<=t;i++)
    cout<<sum[i]<<endl;
	return 0;
}



