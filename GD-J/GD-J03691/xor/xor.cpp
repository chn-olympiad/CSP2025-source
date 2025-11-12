#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],dp[N],b[1<<21];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	memset(b,-1,sizeof(b));
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i-1],(b[a[i]^m]==-1)?0:dp[b[a[i]^m]]+1);
		b[a[i]]=i;
	}
	printf("%d",dp[n]);
	return 0;
}
