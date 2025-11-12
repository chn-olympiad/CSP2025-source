#include<bits/stdc++.h>
using namespace std;
const int N=500+5;
const int SN=18+2;
const long long p=998244353;
char s[N];
int c[N],q[N];
long long dp[1<<SN][SN],fac[N];
long long my_pow(long long x,long long y)
{
    long long ans=1;
    while(y)
    {
        if(y&1)ans*=x,ans%=p;
        x*=x;
        x%=p;
        y>>=1;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    if(n<=18)
    {
        dp[0][0]=1;
        int sz;
        for(int i=0;i<(1<<n);i++)
        {
            sz=0;
            for(int j=0;j<n;j++)if(i&(1<<j))sz++;
            for(int j=0;j<=sz;j++)
            {
    //            cout<<"Nw:"<<i<<' '<<j<<' '<<dp[i][j]<<endl;
                for(int k=0;k<n;k++)
                {
                    if(!(i&(1<<k)))
                    {
                        dp[i|(1<<k)][j+(c[k+1]>sz-j&&s[sz+1]-'0')]+=dp[i][j];
                        dp[i|(1<<k)][j+(c[k+1]>sz-j&&s[sz+1]-'0')]%=p;
                    }
                }
            }
        }
        long long ans=0;
        for(int i=m;i<=n;i++)ans+=dp[(1<<n)-1][i],ans%=p;
        cout<<ans<<endl;
    }
    else if(m==n)
    {
        long long ans=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0'||c[i]==0)
            {
                ans=0;
                break;
            }
            ans*=1ll*i;
            ans%=p;
        }
        cout<<ans<<endl;
    }
    else if(m==1)
    {
        sort(c+1,c+1+n);
        for(int i=1;i<=n;i++)q[c[i]]++;
        fac[0]=1;
        for(int i=1;i<=n;i++)q[i]+=q[i-1],fac[i]=fac[i-1]*(1ll*i)%p;
        int hv=0;
        long long ans=0,w=1;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='1')
            {
                hv++;
                ans+=w*(n-q[i-1])%p*fac[n-hv]%p;
                ans%=p;
                w*=q[i-1];
                w%=p;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
