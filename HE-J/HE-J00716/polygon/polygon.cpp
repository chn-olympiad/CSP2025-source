#include<bits/stdc++.h>
using namespace std;
int n,a[50001];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		int x=n-i+1;
		for(int j=x;j>=1;j--)
		{
			ans+=(j+1)*j/2;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
