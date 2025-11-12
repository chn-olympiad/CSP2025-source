#include<bits/stdc++.h>
using namespace std;
int re[50005]={};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int a[n+5];
	bool flagA=true,flagB=true,flagC=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flagA=false;
		if(a[i]>1) flagB=false;
		if(a[i>255]) flagC=false;
	}
	if(k==0 && flagA) cout<<n/2;
	else if(k<=1 && flagB)
	{
		if(k==0)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(re[i]==0 && a[i]==a[i+1])
				{
					ans++;
					re[i]=1;
				}
			}
			cout<<ans;
		}
		if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(re[i]==0 && a[i]!=a[i+1])
				{
					ans++;
					re[i]=1;
				}
			}
			cout<<ans;			
		}
	}
	
	return 0;
} 
