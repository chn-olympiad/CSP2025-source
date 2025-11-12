#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,z;
	long long n=0,temp;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		long long n1=n/2;   
		long long a[n+1][4];
		long long sum[4][n+1];
		long long zong=0;  
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
	    for(int j=1;j<=n;j++)
	    {
	    	cin>>a[j][1]>>a[j][2]>>a[j][3];
	    }
	    if(n==2)
	    {
	    	zong=((a[1][1]+a[2][2])>(a[1][1]+a[2][3])?(a[1][1]+a[2][2]):(a[1][1]+a[2][3]));
	    	temp=zong;
	    	zong=(temp>(a[1][2]+a[2][1])?temp:(a[1][2]+a[2][1]));
	    	temp=zong;
	    	zong=(temp>(a[1][2]+a[2][3])?temp:(a[1][2]+a[2][3]));
	    	temp=zong;
	    	zong=(temp>(a[1][3]+a[2][1])?temp:(a[1][3]+a[2][1]));
	    	temp=zong;
	    	zong=(temp>(a[1][3]+a[2][2])?temp:(a[1][3]+a[2][2]));
	    	cout<<zong<<endl;
	    	zong=0;
		}
	    else
	    {
	    	for(int j=1;j<=n;j++)
	    {
	    	
			if(a[j][1]>a[j][2]&&a[j][1]>a[j][3])
			{
				z=1;temp=a[j][1];
			}
			else if(a[j][2]>a[j][1]&&a[j][2]>a[j][3])
			{
				z=2;temp=a[j][2];
			}
			else {
				z=3;temp=a[j][3];
			}
	        sum[z][j]=temp;
	    }
	    for(int j=1;j<=3;j++)
	    {
	    	sort(sum[j],sum[j]+(n+1));
			for(int k=n;k>n1;k--)
	    	{
				zong+=sum[j][k];
			}
	    	
		}
		cout<<zong<<endl;
		zong=0;
		}
	}
	
	return 0;
}