#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define maxn 1000005
using namespace std;
int a[maxn],s[maxn];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			ans++;
			continue;
		}
		else
		{
			for(int j=i+1;j<=n;j++)
			{
				if((s[j]^s[i-1])==k)
				{
					ans++;
					i=j+1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
