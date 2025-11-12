#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int ans=0;
void db(int i,int j)
{
	int b[5005];
	b[1]=j;
	int sum[5005];
	while(i)
	{
		for(int k=2;k<=n;k++)
	    {
		  	sum[k]=b[1]+a[k]+a[k+1];
			if(sum[k]>a[k+1]*2)
			{
			  	ans++;
			}
		}
		
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	int c=1;
	for(int i=3;i<=n;i++)
	{
		db(i,a[c]);
		c++;
	}
	cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
} 
