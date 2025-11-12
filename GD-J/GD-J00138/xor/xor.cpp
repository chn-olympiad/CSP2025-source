#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000005],f[1000005],ans,s; 
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s=0;
		for(int j=0;j<i;j++)
		{
			s^=a[i-j];
			if(s==k) f[i]=max(f[i],f[i-j-1]+1);
			else f[i]=max(f[i],f[i-j-1]);
		}
	}
	cout<<f[n];
	return 0;
}
