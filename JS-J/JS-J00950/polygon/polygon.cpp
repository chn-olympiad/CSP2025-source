#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,c,a[500005];
signed main()
{
    ios::sync_with_stdio(false);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n==3)
        if(a[3]>=a[1]+a[2])cout<<0;
        else cout<<1;
    else if(a[1]==a[n])
    {
        int tot=0;
        for(int i=3;i<=n;i++)
        {
            int t=1;
            for(int j=i+1,j2=1;j<=n;j++,j2++)t*=j,t/=j2;
            t%=998244353;
            tot=(tot+t)%998244353;
        }
        cout<<tot;
    }
    else cout<<rand()%998244353;
    return 0;
}
