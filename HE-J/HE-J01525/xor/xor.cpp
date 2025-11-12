#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
map<int,int> mp;
int n,k;
int a[N],c[N],f[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		c[i]=(c[i+1]^a[i]);
	for(int i=1;i<=n;i++)
	{
		mp[c[i]]=i;
		f[i]=f[i-1];
		if(mp[k^c[i+1]])
			f[i]=max(f[i],f[mp[k^c[i+1]]-1]+1);
	}
	printf("%d",f[n]);
	return 0;
}
/*
4 3
2 1 0 3
*/
