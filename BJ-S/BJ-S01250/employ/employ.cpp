#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MOD=998244353;
int N,M;
int a[505],c[505];
LL dp[1<<18][20];//面试过的集合为S，没通过i个
LL f=1;
int PopCount(int x)
{
    int res=0;
    while(x)
    {
        res+=(x&1); x>>=1;
    }
    return res;
}
void Func()
{
    sort(c+1,c+N+1);
    int pos=0;
    LL mul=1;
    for(int i=1;i<=N;i++)
    {
        if(a[i]==0) continue;
        int app=0;//applicant
        for(int j=1;j<=N;j++) if(c[j]<i) app++;
        app-=pos;
        pos++;
        mul=mul*app%MOD;
    }
    for(int i=1;i<=N-pos;i++) mul=mul*i%MOD;
    f=(f-mul)%MOD;
    if(f<0) f+=MOD;
    return;
}
void Func2()
{
    bool flag=1;
    for(int i=1;i<=N;i++)
    {
        if(a[i]==0||c[i]==0) flag=0;
    }
    printf("%lld\n",f*flag);
    exit(0);
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%1d",&a[i]);
    for(int i=1;i<=N;i++) scanf("%d",&c[i]);
    if(N>18)
    {
        for(int i=1;i<=N;i++) f=f*i%MOD;
        if(M==1) Func();
        if(M==N) Func2();
        printf("%lld\n",f);
        return 0;
    }
    dp[0][0]=1;
    for(int st=0;st<(1<<N);st++)
    {
        int x=PopCount(st);
        for(int i=0;i<=x;i++) 
        {
            if(!dp[st][i]) continue;
            for(int j=1;j<=N;j++)
            {
                if(st&(1<<j-1)) continue;
                int nst=st|(1<<j-1);
                if(c[j]<=i||a[x+1]==0) dp[nst][i+1]=(dp[nst][i+1]+dp[st][i])%MOD;
                else dp[nst][i]=(dp[nst][i]+dp[st][i])%MOD; 
            }
        }
    }
    LL ans=0;
    for(int i=0;i<=N-M;i++) ans=(ans+dp[(1<<N)-1][i])%MOD;
    printf("%lld\n",ans);
    return 0;
}