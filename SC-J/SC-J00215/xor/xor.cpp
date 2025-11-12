#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;
int a[N],pre[N],k,f[N],n,ls[N*6];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i]; 
	}
	for(int i=1;i<=n;i++) 
	{
		f[i]=f[i-1];
		int j=ls[pre[i]^k];
		if((pre[j]^pre[i])==k) f[i]=max(f[i],f[j]+1);
		ls[pre[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
} 