#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ans++;
			else if(i<=n&&a[i]==1&&a[i+1]==1) ans++,i++;
		}
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
