//我也不会忘记曾经 如果没有你 我连坐在考场的机会都没有。 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int n,k;
int sum=0;
int a[N],f[N],lan[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<N;i++)
		lan[i]=-1;
	for(i=1;i<=n;i++)
	{
		sum^=a[i];
		f[i]=max(f[i-1],lan[sum^k]+1);
		lan[sum]=f[i];
	}
	printf("%d",f[n]);
	return 0;
}
