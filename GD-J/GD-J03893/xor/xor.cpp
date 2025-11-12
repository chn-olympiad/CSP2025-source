#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,k,a[1000005],last,ans;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int r=1;r<=n;r++)
	{
		int quan=0;
		for(int l=r;l>last;l--)
		{
			quan=quan^a[l];
			if(quan==k)
			{
				ans++;
				last=r;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
