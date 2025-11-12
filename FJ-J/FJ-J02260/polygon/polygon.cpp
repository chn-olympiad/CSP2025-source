#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int a[5005],constant[5005],n,ans;
void solve()
{
	if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
		cout<<1<<"\n";
	else
		cout<<0<<"\n";
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n-2;++i)
		constant[i]=constant[i-1]+i;
	for(int i=1;i<=n-2;++i)
		cout<<constant[i]<<" ";
	cout<<"\n";
	if(n==3)
		solve();
	else
	{
		for(int i=1;i<=n-2;++i)
			ans=((ans+P)%P+(n-2-i+1)*constant[i])%P;
		cout<<ans<<"\n";
	}
	return 0;
}
