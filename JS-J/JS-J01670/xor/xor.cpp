#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int f[n+5][k*2];
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			f[i][j]=f[i-1][j]+f[i-1][j^a[i]];
	printf("%d\n",f[n][k]);
	return 0;
}
