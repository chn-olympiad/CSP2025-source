#include<bits/stdc++.h>
using namespace std;
long long t,n,sum1,sum2,s1,s2,s3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		sum1=sum2=0;
		if(n<1000)
		for(int j=1;j<=n;++j)
		{
		 	for(int k=1;k<=3;++k)
			{
				cin>>s1>>s2>>s3;
				sum1+=s1;
				sum2+=s2;
			}
		}
		else
		for(int j=1;1;++j)
		{
		 	for(int k=1;k<=3;++k)
			{
				cin>>s1>>s2>>s3;
				sum1+=s1;
			}
		}
		cout<<sum1<<sum2;
	}
	return 0;
}
