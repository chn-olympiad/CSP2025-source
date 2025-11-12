#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[500005];
int q[500005];
int lst[3000005];
int g[500005],f[500005];
bool flag[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		q[i]=q[i-1]^a[i];
		lst[q[i]]=i;
		g[i]=lst[q[i]^k];
		if((q[lst[q[i]^k]]^q[i])!=k) flag[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==1) f[i]=f[i-1];
		else f[i]=max(f[i-1],f[g[i]]+1);
	}
	printf("%d",f[n]);
	return 0;
}
/*
4 0
2 1 0 3



*/
