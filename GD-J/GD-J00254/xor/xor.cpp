#include<iostream>
using namespace std;
int n,k,a[500005],t[500005]={},f[500005]={};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[i]=(t[i-1] ^ a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=1;j<=i;j++)
		{
			if((t[j-1] ^ t[i])==k) f[i]=max(f[i],f[j-1]+1);
		}
	}
	cout<<f[n];
	
	return 0;
}
