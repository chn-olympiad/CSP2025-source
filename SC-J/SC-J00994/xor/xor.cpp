#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],sum[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]^a[i];
	if(k<=1)
	{
		int jl=0,jl2=0,jl3=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
				jl++;
			if(a[i]==1 || a[i]==0)
				jl2++;
			if(a[i]==1)
				jl3++;		
		}
		if(k==0 && jl==n)
		{
			cout<<n/2;
		}
		else if(k<=1 && jl2==n)
		{
			if(k==1)
			{
				cout<<jl3;
			}
			else
			{
				int ans=0;
				for(int i=1;i<=n;i++)
				{
					if(a[i]==0)
						ans++;
					if(a[i]==1 && a[i+1]==1)
						ans++,i++;	
				}
				cout<<ans;
			}
		}
	}		
	return 0;
}