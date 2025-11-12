#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int read()
{
    int x=0,f=1;
    char c;
    c=getchar();
    while((c<'0'||c>'9')&&c!='-')   c=getchar();
    if(c=='-')
    {
        f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int a[500005],sum[500005],dp[500005];
map<int,int>p;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    int n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();

    }
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]^a[i];

        if(a[i]==m)
        {
            dp[i]=dp[i-1]+1;
            p[sum[i]]=i;
            continue;
        }
        dp[i]=dp[i-1];
        int x=sum[i]^m;
        if(x==0)    dp[i]=max(dp[i],1);
        if(p[x]!=0) dp[i]=max(dp[i],dp[p[x]+1]);


        p[sum[i]]=i;
    }
    cout<<dp[n];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
