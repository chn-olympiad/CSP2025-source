#include<bits/stdc++.h>
using namespace std;
int f[3500000];
int g[3500000];
int a[3500000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0;
	memset(g,-0x3f,sizeof(g));
	g[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum^=a[i];
		int c=k^sum;
		if(g[c]>=0)
		f[i]=g[c]+1;
		f[i]=max(f[i],f[i-1]);
		g[sum]=max(g[sum],f[i]);
	}
	printf("%d",f[n]);
	return 0;
}
