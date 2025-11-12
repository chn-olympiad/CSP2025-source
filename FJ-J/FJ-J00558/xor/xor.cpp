#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100002];
long long num[100002];
long long f[100002][20];
long long ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];	
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		int cnt=0;
		for(int j=1;j<=20;j++)
		{
			f[i][j]=f[i-1][j];
		}
		while(x>0)
		{
			cnt++;
			if(x%2==1)
			{
				f[i][cnt]++;
			}
			x/=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int x=1;x<=20;x++)
			{
				int x2=f[j][x]-f[i-1][x];
				if(x2%2==1)
				{
					num[x]=1;
				}else{
					num[x]=0;
				}
			}
			int sum=0;
			int base=1;
			for(int x=1;x<=20;x++)
			{
				sum+=num[x]*base;
				base*=2;
			}
			if(sum==k) 
			{
				ans++;
				i=j;
				break;
			}
			
		}
	}
	cout<<ans;
} 


