#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5050],ans=0;
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
    //hack1~3
    if(n==3)
    {
        if((a[1]+a[2]+a[3])>max(max(a[1],a[2]),a[3])*2)
        {
            ans++;
        }
    }
    cout<<ans%mod;
    return 0;
}
