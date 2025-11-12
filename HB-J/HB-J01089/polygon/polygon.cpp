#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5005;
const long long mod=998244353;
long long s[MAXN];
long long arr[MAXN];

long long ans=0;
long long n;

long long my_Cmul(long long a,long long b)
{
    long long x=1;
    for(long long i=1;i<=b;i++)
    {
        x*=(a-i+1);
        x%=mod;
    }

    long long y=1;
    while(b)
    {
        if(b==0) break;
        y*=b;
        y%=mod;
        b--;
    }

    return (x/y)%mod;
}

void dfs(long long i,long long sum,long long mx,long long bian,long long cnt)
{
    if(bian>n)
    {
        cout<<ans%mod;
        exit(0);
    }
    if(i>n)
    {
        if(cnt==bian)
        {
            if(sum>mx*2)
            {
                ans++;
                ans%=mod;
            }
        }
        if(sum==arr[i])
        {
            dfs(1,0,0,bian+1,0);
        }
        return ;
    }

    if(cnt==bian)
    {
        if(sum>mx*2)
        {
            ans++;
            ans%=mod;
        }
        return ;
    }

    dfs(i+1,sum+s[i],max(s[i],mx),bian,cnt+1);
    dfs(i+1,sum,mx,bian,cnt);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;

    bool flag=true;
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]!=1)
        {
            flag=false;
        }
    }

    for(long long i=n,j=1;i>=1;i--,j++)
    {
        arr[j]=arr[j-1]+s[i];
    }

    if(flag)
    {
        long long res=0;
        for(long long i=4;i<=n;i++)
        {
            res+=my_Cmul(n,i)%mod;
            res%=mod;
        }

        cout<<res%mod;
        return 0;
    }

    dfs(1,0,0,3,0);

    return 0;
}
