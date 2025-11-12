#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ans,f[5005][4];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++)
        cin >>a[i];
    sort(a+1,a+1+n);
    if(n==3)
    {
        sum=a[1]+a[2]+a[3];
        if(sum>a[3]*2)
            cout <<"1";
        else
            cout <<"0";
        return 0;
    }
    else if(n<=20)
    {
        int x;
        for(int i=1;i<=(1<<n);i++)
        {
            sum=0;
            for(int j=1;j<=n;j++)
                if(i&(1<<j))
                {
                    sum+=a[i];
                    x=a[i];
                }
            if(sum>x*2)
                ans++;
        }
        cout <<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        f[i][2]=f[i-1][2]+a[i];
        if(a[i]==a[i-1])
            f[i][3]=f[i-1][3]+1;
    }
    for(int i=3;i<=n;i++)
        for(int j=0;j<=i;j++)
        {
            if(f[i][2]-f[j][2]>a[i]*2)
                f[i][1]+=(f[j][1]*f[j][3])%998244353;
            else
                break;
        }
    for(int i=1;i<=n;i++)
    {
        ans+=f[i][1];
        ans%=998244353;
    }
    cout <<ans;
    return 0;
}
