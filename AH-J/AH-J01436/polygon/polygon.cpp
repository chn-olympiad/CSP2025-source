#include <bits/stdc++.h>
/*woxihuanwyh*/
using namespace std;
const int N=150;
int a[N],n,m,d;
long long ans,s=1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]+a[j]>a[j+1]) ans++;
            else if(a[i]+a[i+1]>a[j]&&i+1!=j) ans++;
        }
    ans%=998244353;
    for(int i=n;i>=4;i--)
    {
        int t=0;
        s=1;
        for(int j=n;j>=1;j--)
        {
            int c=n-t;
            s=(s*j)%998244353;
            s/=c;
            t++;
        }
        ans=(ans+s)%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
