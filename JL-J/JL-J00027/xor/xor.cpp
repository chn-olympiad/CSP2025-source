#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500050],ans[5050][5050],sum[5050][5050],maxx[5050][5050];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int l=1;l<=n;l++)
		for(int r=l;r<=n;r++)
		{
			maxx[l][r]=maxx[l][r-1];
			if(l==r) sum[l][r]=a[l];
				else sum[l][r]=(sum[l][r-1]^a[r]);
			if(sum[l][r]==k) maxx[l][r]++;
		}
	for(int i=1;i<=n;i++)
		for(int l=1;l+i-1<=n;l++)
		{
			long long r=l+i-1;
			for(int k=l;k<=r;k++)
				ans[l][r]=max(ans[l][r],max(ans[l-1][r-1],maxx[l][k]+maxx[k][r]));
		}
	printf("%lld",ans[1][n]);
	return 0;
}
