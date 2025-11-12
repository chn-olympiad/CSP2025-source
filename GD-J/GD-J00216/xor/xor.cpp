# include <cstdio>
using namespace std;
int n,k,a[2000007],bz[5000007],f[2000007];
int max(int x,int y){return x>y?x:y;}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bz[0]=1;
	int p=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		p^=a[i];
		if(bz[p^k]>0) f[i]=max(f[i],f[bz[p^k]-1]+1);
		bz[p]=i+1;
	}
	printf("%d",f[n]);
	return 0;
}
