#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],dp,ans[10000005],f[10000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp=dp^a[i];
		if(a[i]==0)
		{
			if(k==0&&dp==0) ans[dp]++;
			continue;                                                                         
		}
		if(f[dp^k]) ans[dp]++;
		if(f[dp]&&f[dp^k]&&k!=0) ans[dp]++;
		f[dp]++;
	}
	int mx=0;
	for(int i=0;i<=10000000;i++)
	{
		mx=max(mx,ans[i]);
	}
	printf("%d",mx);
	return 0;
}