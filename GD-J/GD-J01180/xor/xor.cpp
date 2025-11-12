#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,ans,t[N],s[N],f[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&f[i]);
		if(i==1) s[i]=f[i];
		else s[i]=f[i]^s[i-1];
	}
	for(int i=1;i<n;++i)
	{
		int bj=0;
		for(int l=i;l<n;++l)
		{
			if(f[l]==k)
			{
				ans++;
				break;
			}
			for(int r=l+1;r<=n;++r)
			{
				if(s[r]^s[l-1]==k)
				{
					ans++;
					bj=1;
					i=r+1;
					t[r]=1;
					break;
				}
			}
			if(bj==1) break;
		}
	}
	if(t[n]==0&&f[n]==k) ans++;
	printf("%lld",ans);
	return 0;
}
