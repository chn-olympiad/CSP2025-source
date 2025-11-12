#include<bits/stdc++.h>
using namespace std;
long long n,k,a[510000],s[510000],f[510000],x;
unordered_map <long long,long long> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(s[i-1]^a[i]); 
	}
	mp[0]=0;
	for(long long i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		x=(s[i]^k);
		if(mp.find(x)!=mp.end())
		{
			f[i]=max(f[i],f[mp[x]]+1);
		}
		mp[s[i]]=i;
	}
	cout<<f[n];
	return 0;
}
