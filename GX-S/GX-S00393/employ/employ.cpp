#include<cstdio>
using namespace std;

const int nn=505;
const long long mod=998244353;

long long minn(long long x,long long y)
{
    if(x<y) return x;
    return y;
}

long long J[nn],NJ[nn];
long long my_pow(long long,long long);
long long suanZHS(int,int);

int n,m;
char a[nn];
int b[nn];

int sumb[nn];

long long f[nn][nn];
long long g[nn];

void work12();
void work15();
void work16();

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    J[0]=1;for(int i=1;i<nn;i++) J[i]=J[i-1]*i%mod;
    NJ[nn-1]=my_pow(J[nn-1],mod-2);
    for(int i=nn-1;i>=0;i--) NJ[i]=NJ[i+1]*(i+1)%mod;

    scanf("%d%d",&n,&m);
    scanf("%s",a+1);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);

    for(int i=1;i<=n;i++) sumb[b[i]]++;
    for(int i=n-1;i>=0;i--) sumb[i]+=sumb[i+1];

    if(n==m)
    {
        work15();
        return 0;
    }

    if(m==1)
    {
        work12();
        return 0;
    }

    /*{
        bool bo=1;
        for(int i=1;i<=n;i++) if(a[i]=='0') bo=0;
        if(bo) work16();
    }*/

    return 0;
}


void work12()
{
    long long ans=0,now1=1,now2=n;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='0') continue;
        now2--;

        ans=(ans+now1*sumb[i]%mod*J[now2])%mod;
        now1=now1*minn(now2,n-sumb[i])%mod;
    }

    printf("%lld",ans);

    return;
}
void work15()
{
    for(int qw=m;qw<=n;qw++)
    {
        f[n+1][0]=1;
        for(int i=n;i;i--) for(int j=0;j<=qw;j++)
        {
            f[i][j]=f[i+1][j];
            if(a[i]=='1'&&j&&i+j-qw>=0&&sumb[i+j-qw]-j+1>0)
            {
                f[i][j]=(f[i][j]+f[i+1][j-1]*(sumb[i+j-qw]-j+1))%mod;
            }
            //printf("f[%d][%d][%d]=%lld\n",qw,i,j,f[i][j]);//
        }
        g[qw]=f[1][qw]*J[n-qw]%mod;

        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
    }

    long long ans15=0;
    for(int i=n;i>=m;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            g[i]=(g[i]-g[j]*suanZHS(j,i))%mod;
        }
        if(g[i]<0) g[i]+=mod;
        ans15+=g[i];
        if(ans15>=mod) ans15-=mod;
    }

    printf("%lld",ans15);

    return;
}
void work16()
{


    return;
}

long long my_pow(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
long long suanZHS(int x,int y)
{
    return J[x]*NJ[y]%mod*NJ[x-y];
}
