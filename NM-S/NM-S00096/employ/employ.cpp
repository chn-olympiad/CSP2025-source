#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int p[510]={0};
int n=0;
int bukeyi(int f)
{
    int e=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i]>=f)
        {
            e++;
        }
    }
    return e;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int m=0;
    cin>>n>>m;

    int tt=0;
    char a;
    while(cin>>a)
    {
        if(a!='0')
        {
            tt++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    sort(p+1,p+n+1);
    long long ans=1;
    int x=0;
    int tag=0;
    int nx=0;
    for(int i=0;i<n;i++)
    {
        /*if(tag==m)
        {
            ans*=(n-i)%MOD;
            continue;
        }

        if(a[i]-'0'==1)
        {
            ans*=(n-i)%MOD;
            tag++;
        }
        else
        {
            int t=bukeyi(nx);
            ans*=abs((n-t+x+1))%MOD;
            x=t;
            nx++;
        }*/
        ans=(n-tt-i)%MOD*ans%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
