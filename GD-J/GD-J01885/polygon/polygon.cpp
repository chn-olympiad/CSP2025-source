#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	long long ans=n*n;
	if(n<3) cout<<"0";
	else if(a[1]+a[2]+a[3]>a[3]*2&&n==3) cout<<"1";
	else if(n>3) 
	{
		for(int i=2;i<=n-1;i++)
		{
			ans-=i;
		}
		cout<<ans%998244353;
	} 
	return 0;
}
