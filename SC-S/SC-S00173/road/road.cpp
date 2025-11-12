#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int f[1000005],s[1000005],c[1000005],a[4];
int main()
{
	cin>>t;
	for(int p=1;p<=t;p++)
	{
		foropen("club.out","w",stdout);
		int max=0;
		int ans;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) cin>>a[j];
			if(f[i]<a[1])
			{
				f[i]=a[1]+0.1;
				if(a[2]>a[3])
				{
					s[i]=a[2]+0.2;
					c[i]=a[3]+0.3;
				}else{
					c[i]=a[2]+0.2;
					s[i]=a[3]+0.3;	
				}
			}
			if(f[i]<a[2])
			{
				f[i]=a[2]+0.2;
				if(a[1]>a[3])
				{
					s[i]=a[1]+0.1;
					c[i]=a[3]+0.3;
				}else{
					c[i]=a[1]+0.1;
					s[i]=a[3]+0.3;	
				}
			}
			if(f[i]<a[3])
			{
				f[i]=a[3]+0.3;
				if(a[1]>a[2])
				{
					s[i]=a[1]+0.1;
					c[i]=a[2]+0.2;
				}else{
					c[i]=a[1]+0.1;
					s[i]=a[2]+0.2;	
				}
			}
			max=floor(f[i])+max;
			ans=ans+max;
		}
		cout<<max;
	}
	return 0;
}
 