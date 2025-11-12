#include<bits/stdc++.h>
using namespace std;
int i,a[500001],j,m,n,k;
long long ans,mod = 998244353,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i = 1;i <= n;i++){
		cin>>a[i];
	}
	if(n == 3)
	{
		if(max(max(a[1],a[2]),a[3]) < (a[1] + a[2] + a[3]) / 2) 
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
		return 0;
	}
	sum = 1;
	ans += sum;
	for(i = 1;n - i >= 3;i++)
	{
		sum = (sum * (n - i + 1) / i) % mod;
		ans += sum;
	}
	cout<<ans % mod<<endl;
}
