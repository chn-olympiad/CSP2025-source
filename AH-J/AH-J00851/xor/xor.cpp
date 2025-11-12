#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,ans,v[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(a[i]==k) ans++,v[i]=1;
    }
    if(k==1)
    {
		for(int i=1;i<n;i++)
		{
			if(a[i]==0&&a[i+1]==0&&v[i]==0&&v[i+1]==0) 
			{
				ans++;
				v[i]=1;
				v[i+1]=1;
			}
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]==1&&a[i+1]==1&&v[i]==0&&v[i+1]==0) 
			{
				ans++;
				v[i]=1;
				v[i+1]=1;
			}
		}
	}
	cout<<ans;
    return 0;
}
