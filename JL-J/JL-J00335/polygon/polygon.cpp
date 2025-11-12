#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[5005];
long long cnt;
bool f[5005];
long long c(int x,int y)
{
    if(x==y) return 1;
    long long ret1,ret2;
    ret1=ret2=1;
    for(int i=1;i<=y;i++)
    {
        ret1*=i;
        ret1%=mod;
    }
    for(int i=x-y+1;i<=x;i++)
    {
        ret2*=i;
        ret2%=mod;
    }
    return (ret2/ret1);
}
void tfp()
{
    for(int i=3;i<=n;i++)
    {
        cnt+=c(n,i)%mod;
        cnt%=mod;
    }
    printf("%lld",cnt);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(a[n]==0)
    {
        tfp();
        return 0;
    }
    for(m=3;m<=n;m++)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=m;i++) f[i]=1;
        do
        {
            int s=0,ma;
            for(int i=1;i<=n;i++)
            {
                if(f[i]) s+=a[i],ma=a[i];
            }
            if(s>ma*2) cnt++;
            cnt%=mod;
        }while(prev_permutation(f+1,f+1+n));
    }
    printf("%lld",cnt);
    return 0;
}
