#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt=0;
int a[6000];
int b[6000];
ll ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3)
    {

        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[a[i]]++;
    for(int i=1;i<=6000;i++)
        if(b[i]!=0) cnt++;
    for(int i=3;i<=n;i++)
    {
        ll num=0;
        for(int j=1;j<=i;j++)
        {
            num+=a[j];
        }
        if(num<=a[i]*2) continue;
        else
        {
            ans++;
            for(int j=3;j<=i;j++)
            {
                if(num-a[j]>a[i]*2&&a[j]!=a[i]) ans++;
                if(num-a[j]>a[i-1]*2&&a[j]==a[i]) ans++;
            }
        }
        ans%=998;
        ans%=244;
        ans%=353;
    }
    cout<<ans+cnt-1;
    return 0;
}
