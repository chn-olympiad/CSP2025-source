#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(k==0)
	{
		cout<<1;
		return 0;
	} 
	
	int m[500005]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int f=0;
			for(int x=i;x<=j;x++)
			{
				if(m[x]==1)
				{
					f=1;
					break;
				}
			}
			if(f==1) break;
			
			int sum=a[i];
			
			for(int l=i+1;l<=j;l++)
			{
				sum=sum^a[l];
			}
			
			if(sum==k)
			{
				ans++;
				for(int x=i;x<=j;x++)
				{
					m[x]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
