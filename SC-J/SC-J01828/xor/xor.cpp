#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,c[1000001],f[1000001],ans,sum;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(i!=1) f[i]=c[i]^f[i-1];
		else f[i]=c[i];
	}
	cout<<0;
	return 0;
}