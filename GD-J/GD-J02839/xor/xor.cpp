#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[500005],t[1048576],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<(1<<20);i++)t[i]=-1;
	for(int i=1;i<=n;i++)
	{
		s^=a[i];
		f[i]=f[i-1];
		if(t[k^s]>=0)f[i]=max(f[i],f[t[k^s]]+1);
		t[s]=i;
	}
	cout<<f[n];
	return 0;
}
