#include<bits/stdc++.h>
using namespace std;
/*

*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
const int N=20,M=510,mod=998244353;
int n,m,i,j,k,c[M];
char s[M];
int f[1<<N][N],cnt,ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scan>>n>>m;
    scanf("%s",s+1);
    for (i=0;i<n;i++) scan>>c[i];
    if (m==n)
    {
        for (i=1;i<=n;i++)
        {
            if (s[i]=='0'||c[i]==0)
            {
                puts("0");
                return 0;
            }
        }
        puts("1");
        return 0;
    }
    f[0][0]=1;
    for (i=0;i<(1<<n);i++)
    {
        cnt=__builtin_popcount(i);
        for (j=0;j<n;j++)
        {
            if ((i>>j)&1) continue;
            for (k=0;k<=cnt;k++)
            {
                if (cnt-k>=c[j]||s[cnt+1]=='0') f[i^(1<<j)][k]=(f[i^(1<<j)][k]+f[i][k])%mod;
                else f[i^(1<<j)][k+1]=(f[i^(1<<j)][k+1]+f[i][k])%mod;
            }
        }
    }
    for (k=m;k<=n;k++) ans=(ans+f[(1<<n)-1][k])%mod;
    printf("%d\n",ans);
    return 0;
}