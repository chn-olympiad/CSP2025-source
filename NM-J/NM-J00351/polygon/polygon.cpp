#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]<=a[k]*2) break;
				ans++;
			}
			ans%=998244353;
		}
	}
	ans%=998244353;
	cout<<ans;
	return 0;
}
