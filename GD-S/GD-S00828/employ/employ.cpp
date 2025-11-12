#include<cstdio>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fe(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define jia(o,p) o=(o+p)%M
const int N=500+5,M=998244353;
int n,m,d[N],sum[N],f[2][N][N],fz[N],fm[N];
char a[N];
int ksm(int s,int p)
{
	int z=1;
	while(p>=1)
	{
		if(p&1) z=(ll)z*s%M;
		s=(ll)s*s%M,p>>=1;
	}
	return z;
}
inline int C(int o,int p){return o<p||p<0?0:(ll)fz[o]*fm[p]%M*fm[o-p]%M;}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,a+1),fz[0]=fm[0]=1;
	fo(i,1,n)
	{
		int x;
		scanf("%d",&x),++d[x];
	}
	sum[0]=d[0];
	fo(i,1,n) sum[i]=d[i]+sum[i-1],fz[i]=(ll)fz[i-1]*i%M,fm[i]=ksm(fz[i],M-2);
	f[0][0][d[0]]=1;
	fo(i,1,n)
	{
		fo(j,0,n) fo(k,0,n) if(f[0][j][k])
		{
			int z=f[0][j][k];
			if(a[i]=='0')
			{
				fo(l,0,d[j+1]) if(k-1+d[j+1]-l>=0) jia(f[1][j+1][k-1+d[j+1]-l],(ll)z*(k+d[j+1]-l)%M*C(d[j+1],l)%M*fz[l]%M*C(i-1-(sum[j]-k),l));
				fo(l,0,d[j+1]) jia(f[1][j+1][k+d[j+1]-l],(ll)z*C(d[j+1],l)%M*fz[l]%M*C(i-1-(sum[j]-k),l));
			}
			else
			{
				if(k) fo(l,0,d[j+1]) jia(f[1][j+1][k-1+d[j+1]-l],(ll)z*k%M*C(d[j+1],l)%M*fz[l]%M*C(i-1-(sum[j]-k),l));
				jia(f[1][j][k],z);
			}
		}
//		if(i==2) fo(j,0,n) fo(k,0,n) if(f[1][j][k]) printf("%d_%d_%d ",j,k,f[1][j][k]);
		fo(j,0,n) fo(k,0,n) f[0][j][k]=f[1][j][k],f[1][j][k]=0;
	}
	int ans=0;
	fo(j,0,n-m) jia(ans,(ll)f[0][j][0]*fz[sum[n]-sum[j]]);
	printf("%d",ans);
	return 0;
}
