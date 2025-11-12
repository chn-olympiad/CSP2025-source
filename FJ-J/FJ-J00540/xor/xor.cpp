#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],s[500010],f[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i-1; j>=0; j--)
		{
			if((s[i]^s[j])==k)
			{
				f[i]=max(f[i],f[j]+1);
				break;
			}
			else
			{
				if(f[j]<f[i])
				{
					break;
				}
				f[i]=max(f[i],f[j]);
			}
		}
	}
	cout<<f[n];
	return 0;
}
