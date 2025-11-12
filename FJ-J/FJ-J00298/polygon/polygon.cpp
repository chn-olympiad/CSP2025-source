#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
const int N=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n==3)
	{
		if ((a[1]+a[2]+a[3])>max(a[1],max(a[2],a[3]))*2)cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for (int i=3;i<=n;i++)
		for (int j=1;j<=n-i;j++)
		{
			int all=0,maxx=0;
			for (int k=j;k<=i;k++)
				all+=a[k],maxx=max(maxx,a[k]);
			if (all>2*maxx)ans=(ans+1)%N;
		}
	cout<<ans;
	return 0;
}

