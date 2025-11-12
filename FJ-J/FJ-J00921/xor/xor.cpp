#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int fl=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0&&fl==1)fl=2;
		if(a[i]>1)fl=3;
	}
	if(fl==1)cout<<(n/2);
	else if(fl==2)
	{
		if(k==1)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			cout<<ans;
		}
		else if(k==0)
		{
			int ans0=0,ans1=0;
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans1++;
				else if(a[i]==0)ans0++;
			cout<<ans0+(ans1/2);
		}
	}
	return 0;
}
