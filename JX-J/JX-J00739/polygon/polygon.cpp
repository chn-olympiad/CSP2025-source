#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,h[5005],maxn;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	h[1]=a[1];
	for(int i=2;i<=n;i++)
	h[i]=a[i]+h[i-1];
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			if((h[j]-h[i-1])>(j*2))
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
