#include <bits/stdc++.h>
using namespace std;

long long n,k,a[600000],ans,cnt;
bool s[600000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]==k)
	{
			s[i]=1;
			ans++;
		}
	}
	cout<<ans<<" ";
	for (int i=1;i<=n;i++)
	{
		cnt=a[i];
		if (s[i]==1)
			continue;
		for (int j=i+1;j<=n;j++)
		{
			if (a[j]==1)
			{
				break;
			}
			cnt^=a[j];
			if (cnt==k)
			{
				ans++;
				i=j-1;
			}
		}
	}
	cout<<ans;
	return 0;
}