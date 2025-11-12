#include<cstdio>
using namespace std;
#define LL long long
const int N=510,M=19,mod=998244353;
int n,m,a[N],b[N],c[N];
LL f[N][N],ans;
LL fc[N],ifc[N];
LL g[1<<(M-1)][M],h[1<<(M-1)][M];
LL mi(LL x,int y)
{
    if(!y) return 1;
    if(!(y&1)) return mi(x*x%mod,y/2);
    return x*mi(x*x%mod,y/2)%mod;
}
bool ck1()
{
    for(int i=1;i<=n;i++) if(a[i]==0) return 0;
    return 1;
}
void init()
{
    fc[0]=1;
    for(int i=1;i<N;i++) fc[i]=fc[i-1]*i%mod;
    ifc[N-1]=mi(fc[N-1],mod-2);
    for(int i=N-2;i>=0;i--) ifc[i]=ifc[i+1]*(i+1)%mod;
}
LL A(int x,int y)
{
	if(y==0) return 1;
    if(x<0||x<y) return 0;
    return fc[x]*ifc[x-y]%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        b[c[i]]++;
    }
    if(m==n)
    {
    	for(int i=1;i<=n;i++)
    	{
    		if(a[i]==0||c[i]==0){printf("0");return 0;}
		}
		printf("%lld",fc[n]);
		return 0;
	}
    if(ck1())
    {
        int s=b[0];
        f[0][b[0]]=fc[b[0]];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
            	if(!f[i-1][j]) continue;
                for(int k=0;k<=b[i];k++)
                {
                    LL s1=A(j+k-i,k),s2=A(s+b[i]-(j+k-i)-1,b[i]-k);
                    (f[i][j+k]+=f[i-1][j]*s1%mod*s2%mod)%=mod;
                }
            }
            s+=b[i];
        }
        for(int i=0;i<=n-m;i++) ans+=f[n][i];
        ans%=mod;
        printf("%lld",ans);
        return 0;
    }
    int S=1<<n;
    g[0][0]=1;
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<S;j++)
    	{
    		for(int k=0;k<=i;k++)
    		{
    			if(!g[j][k]) continue;
    			for(int l=1;l<=n;l++)
    			{
    				if(!(j&(1<<(l-1))))
    				{
    					if(k>=c[l]||a[i]==0) (h[j^(1<<(l-1))][k+1]+=g[j][k])%=mod;
    					else (h[j^(1<<(l-1))][k]+=g[j][k])%=mod;
					}
				}
			}
		}
		for(int j=0;j<S;j++)
		{
			for(int k=0;k<=i;k++) g[j][k]=h[j][k],h[j][k]=0;	
		}
	}
	for(int i=0;i<=n-m;i++) ans=(ans+g[S-1][i])%mod;
	ans%=mod;
	printf("%lld",ans);
}
