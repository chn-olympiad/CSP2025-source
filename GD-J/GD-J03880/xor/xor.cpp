#include<bits/stdc++.h>
#define int long long
using namespace std;
int num[2000005],a[500005];
int fr[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],fr[i]=fr[i-1]^a[i];
	int l=0,r=1;
	num[0]=1;
	while(r<=n)
	{
		if(num[k^fr[r]]>0)
		{
			ans++;
			while(l<r) num[fr[l]]--,l++;
		}
		num[fr[r]]++;
		r++;
	}
	cout<<ans;
	return 0;
}
