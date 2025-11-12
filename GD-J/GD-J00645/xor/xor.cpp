#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
	cin>>n>>k;
	a[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ans++;
			else 
			{
				if(i>=2)
				{
					if(a[i-1]==1) ans++;
					if(a[i+1]==1) ans--;	
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
			else 
			{
				if(a[i-1]==0) ans++;
				if(a[i+1]==0) ans--;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
/*
	
	*/
