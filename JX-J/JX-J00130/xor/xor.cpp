#include<bits/stdc++.h>
using namespace std;
int a[500010],x[500010],f[500010];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	for(int i=n;i>=1;i--)
		for(int j=i;j<=n;j++)
			if((x[j]^x[i-1])==k)
				f[i]=max(f[i],f[j+1]+1);
	cout<<f[1];
	return 0;
}
