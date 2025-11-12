#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1200000;
int n,k,a[N],f[M],ans[N],zans;
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	memset(f,-1,sizeof f);
	f[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	for(int i=1;i<=n;i++) 
	{
		ans[i]=max(ans[i-1],f[a[i]^k]+1);
		f[a[i]]=max(f[a[i]],ans[i]);
		zans=max(zans,ans[i]);
	}
	printf("%d",zans);
	return 0;
}
