#include <bits/stdc++.h>
using namespace std;
long long n,m;
char s[505];
long long c[1010];
long long p[505];
long long ans=1;
bool flaga=true;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]!='1')
        {
            flaga=false;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(flaga==true)
    {
        for(long long i=1;i<=n;i++)
        {
            ans=ans*i%998244353;
        }
        cout<<ans;
    }
    /*
    sort(c+1,c+1+n);
    for(int i=1;i<=n;i++)
    {
        c[i+n]=c[i];
    }
    for(int i=n-c[1]+1;i<=n+n-c[1]+1;i++)
    {
        p[i+c[1-n]]=c[i];
    }
    */
    return 0;
}
