#include<bits/stdc++.h>
using namespace std;
char s[11000];
long long a[1100],b[1100];
long long mod=998244353;
long long ssum[1100];
long long use[1100];
long long p[1100];
long long n,m,anss;
bool check()
{
    long long i,sum;
    sum=0;
    for(i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            sum++;
            continue;
        }
        if(sum>=a[p[i]])
        {
            sum++;
        }
    }
    if(n-sum>=m)return true;
    return false;
}
void dfs(long long x)
{
    long long i;
    if(x>n)
    {
        if(check())
        {
            anss++;
        }
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(use[i]==1)continue;
        use[i]=1;
        p[x]=i;
        dfs(x+1);
        use[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long sum,mm,ans,ans1,i,j,sum1;
    scanf("%lld%lld",&n,&m);
    scanf("%s",s+1);
    sum=0;
    for(i=1;i<=n;i++)
    {
        b[i]=(s[i]-'0');
        sum+=b[i];
    }
    mm=110000;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        mm=min(mm,a[i]);
        ssum[a[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        ssum[i]+=ssum[i-1];
    }
    if(m==n)
    {
        if(mm==0||sum!=n)printf("0");
        else
        {
            ans=1;
            for(i=2;i<=n;i++)
            {
                ans*=i;
                ans%=mod;
            }
            printf("%lld",ans);
        }
        return 0;
    }
    if(m==1)
    {
        ans=1;
        ans1=1;
        sum1=0;
        for(i=1;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
            if(b[i]==0)continue;
            ans1*=(ssum[i-1]-sum1);
            ans1%=mod;
            sum1++;
        }
        for(i=1;i<=n-sum;i++)
        {
            ans1*=i;
            ans1%=mod;
        }
        ans-=ans1;
        ans%=mod;
        if(ans<0)ans+=mod;
        printf("%lld",ans);
        return 0;
    }
    if(n<=10)
    {
        anss=0;
        dfs(1);
        printf("%lld",anss);
        return 0;
    }
    return 0;
}
