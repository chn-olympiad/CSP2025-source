#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],f[500005];
map <int,int> mp,mp1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d%d",&n,&k,&a[1]);
	s[1]=a[1];
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=a[i]^s[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if (s[i]==k)
			f[i]=max(f[i],1);
		if (mp1[s[i]^k]==1)
			f[i]=max(f[i],mp[s[i]^k]+1);
		mp[s[i]]=max(mp[s[i]],f[i]);
		mp1[s[i]]=1;
	}
	cout<<f[n];
	return 0;
}
