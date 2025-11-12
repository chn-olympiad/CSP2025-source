#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll M=5e5+5;
ll n,k,a[M],f[M],b[M],Max;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=1;j<=i;j++)
		{
			if((b[i]^b[j-1])==k)
			{
				//cout<<j<<" "<<i<<endl;
				f[i]=max(f[i],f[j-1]+1);
			}
		}
		Max=max(Max,f[i]);
		//cout<<i<<" "<<f[i]<<endl;
	}
	cout<<Max;
	return 0;
}


