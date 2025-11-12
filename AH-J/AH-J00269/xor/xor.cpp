#include <bits/stdc++.h>
using namespace std;
const int m=5*1e5+9,p=pow(2,20)+5;
long long n,k,a[m],b[m],f[p],ans,l=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if((a[l]^b[i]^b[l])==k)
		{
			ans++;
			l=i+1;
		}
	}
	cout<<ans;
	return 0;
}
