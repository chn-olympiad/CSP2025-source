#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+5,L=(1<<20)+5;
int n,m,a[N],pre[N],qz[N],num[L],maxx[N];
int f[N],ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		qz[i]=(qz[i-1]^a[i]);
		pre[i]=num[(m^qz[i])];
		num[qz[i]]=i;
	}
//	for(int i=1;i<=n;i++)
//		printf("%d %d\n",i,pre[i]);
	for(int i=1;i<=n;i++)
	{
		if(pre[i]==0)
		{
			if(qz[i]==m) f[i]=1;
		}
		else
		{
			f[i]=maxx[pre[i]]+1;
		}
		ans=max(ans,f[i]);
		maxx[i]=max(maxx[i-1],f[i]);
	}
	printf("%d",ans);
	return 0;
}
