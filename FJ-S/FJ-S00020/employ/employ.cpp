#include<bits/stdc++.h>
using namespace std;
int a[505],b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if (m==n)
	{
		cout<<'0';
		return 0;
	}
	int sum=0;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i];
		if (a[i]==0)
		{
			sum++;
		}
	}
	if (sum==n)
	{
		cout<<0;
		return 0;
	}
	for (int i=1; i<=n; i++)
	{
		cin>>b[i];
	}
	int ans=1;
	for (int i=n; i>=2; i--)
	{
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
