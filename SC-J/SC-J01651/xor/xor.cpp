#include<bits/stdc++.h>
using namespace std;
long long k;
int n;
long long a[500050]={0};
long long dp[1001][1001]={0};
void worka()
{
	cout<<1<<endl;
}
void workb()
{
	long long ans=0;
	if(k==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				if(a[i+1]==1)
				{
					ans++;
					i++;
				}
			}
			else
				ans++;
		}
	}
	else
	{
		for(int i=0;i<n;i++)
			if(a[i]==1)
				ans++;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(k<=1&&a[3]<=1&&a[5]<=1)
		workb();
	return 0;
} 
//Hello world? Hello world! HELLO WORLD!!!!