#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n,a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ret=0;
	for(int bin=1;bin<(1<<n);bin++)
	{
		int sum=0,mx=0;
		int bbin=bin;
		int i=0;
		while(bbin!=0)
		{
			i++;
			int bit=bbin%2;
			bbin/=2;
			if(bit)
			{
				mx=max(mx,a[i]);
				sum+=a[i];
			}
		}
		if(sum>2*mx&&i>=3)
		{
			ret++;
		}
	}
	cout<<1ll*ret%998244353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}