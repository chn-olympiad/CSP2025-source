#include<bits/stdc++.h>
using namespace std;
const int N=4e6+5;
int f[N],g[N];
int a[N];
int n,k;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	f[0]=0;
	
	int sum=0;
	g[0]=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		sum^=a[i];
		if (g[sum^k]!=-1)
			f[i]=max(f[i],g[sum^k]+1);
		
		g[sum]=max(g[sum],f[i]);
	}
	printf("%d",f[n]);
	return 0;
}

