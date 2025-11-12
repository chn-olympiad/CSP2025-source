#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,flag,sum0,sum1,flags,ans1,ans0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1])flag=1;
		if(a[i]==1){sum1++;if(sum1%2==0)ans0++;}
		else if(a[i]==0){if(sum1%2==0)ans0++;sum0++;}
		else flags=1;
	}
	if(flag==0&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	if(flags==0)
	{
		if(k==0)
		{
			if(ans0)cout<<ans0;
			else cout<<n;
		}
		if(k==1)
		{
			cout<<sum1;
		}
		return 0;
	}
	return 0;
}


