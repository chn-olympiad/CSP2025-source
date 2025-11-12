#include<bits/stdc++.h>
using namespace std;
int a[10000000],b[10000000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	string s1,s2,s3;
	int n,p,x=1,ans=0,sum,l,h,z;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		x=1;
		while(a[i])
		{
			b[i]+=(a[i]%2)*x;
			a[i]/=2;
			x*=10;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			sum=0;
			s1=b[i];
   			l=1;
   			h=j;
	 		while(l<=j)
   			{
				s2=b[h];
				for(int k=max(s1.size(),s2.size());k>=1;k--)
				{
					if(s1[k]+s2[k]>0)
					{
						sum+=s1[k]+s2[k];
					}
				}
				if(sum==p)
				{
					ans++;
				}
				h++;
				l++;
			}
			
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
