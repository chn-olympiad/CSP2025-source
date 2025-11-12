#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans,k,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		k+=a[i];
	}
	if(k>a[n]*2)
	{
		ans++;
	}
	cout<<ans;
	return 0;
}
