#include<bits/stdc++.h>
using namespace std;
int a[500005];
int f[500005];
int sum[500005];
int ma[2000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	ma[0]=0;
	for(int i=1;i<(1<<20);i++) ma[i]=-10000;
	for(int i=1;i<=n;i++)
	{
		f[i]=max(f[i-1],ma[sum[i]^k]+1);
		ma[sum[i]]=max(ma[sum[i]],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}
