#include<bits/stdc++.h>
using namespace std;
char s[510];
int c[1010],cnt,a[1010];
const int mod=998244353;
int f(int n)
{
    int ans=1;
    for(int i=2;i<=n;i++)
        ans=(ans*i)%mod;
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,flag=1,ans=0;
    cin>>n>>m;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0') flag=0;
        else a[++cnt]=i;
    }
    if(flag)
    {
        sort(c+1,c+n+1);
        for(int i=1,j=1;i<=n;i++)
        {
            while(i-1>=c[j])
                j++;
            ans=(ans+c[j]-i+1)%mod;
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        ans=0;
        for(int i=1,j=1;i<=n;i++)
        {
            ans=(ans+(a[c[i]]-c[i])*f(n-1)%mod)%mod;
        }
        cout<<ans;
    }
    return 0;
}
