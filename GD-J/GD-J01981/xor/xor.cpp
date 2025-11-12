#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt[i]=a[i]^cnt[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l+i-1<=n;l++)
		{
			if(cnt[l+i-1]^cnt[l-1]==k)
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
