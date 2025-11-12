#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],t[500005],f[500005];
map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		t[i]=t[i-1]^a[i];
	mp[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if((mp[k^t[i]]!=0)||((k^t[i])==0))
			f[i]=max(f[i],f[mp[k^t[i]]]+1);
		mp[t[i]]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}
