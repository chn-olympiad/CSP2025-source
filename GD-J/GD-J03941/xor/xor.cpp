#include<bits/stdc++.h>
using namespace std;
long long s[1000005];
long long a[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		if(s[i]==k)
		ans++;
		for(long long j=i+1;j<=n;j++)
		{
			if((s[i]^s[j])==k)
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
