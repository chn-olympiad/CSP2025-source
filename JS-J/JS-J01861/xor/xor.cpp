#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=5e5+5;
int n,m,a[N],dp[N],s[N];
unordered_map<int,int> mp;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        s[i]=s[i-1]^a[i];
    }
    mp[0]=0;
    for(int i=1,x;i<=n;i++)
    {
        dp[i]=dp[i-1];
        x=s[i]^m;
        if(mp.count(x))
            dp[i]=max(dp[mp[x]]+1,dp[i]);
        mp[s[i]]=i;
    //    cout<<dp[i]<<endl;
    }
    write(dp[n]);
    return 0;
}
