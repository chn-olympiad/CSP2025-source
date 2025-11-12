#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k,sum[N],f[N];
template<typename T>void qr(T& x)
{
	x=0;int f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	memset(sum,0,sizeof(sum));memset(f,0,sizeof(f));
	qr(n);qr(k);
	int sum_0=0;
	for(int i=1;i<=n;i++)qr(a[i]),sum_0+=(a[i]==0);
	if(k==0){printf("%d\n",sum_0);return 0;}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]^a[i];
	f[1]=(a[1]==k);
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			f[i]=max(f[i],f[j-1]+((sum[i]^sum[j-1])==k));
//			printf("%d:%d\n",i,f[j-1]+((sum[i]^sum[j-1])==k));
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",sum[i]);puts("");
	printf("%d\n",f[n]);
	return 0;
}
