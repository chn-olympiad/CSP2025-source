#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long cnt=0;
int maxx(int a,int b,int c)
{
    return max(max(a,b),c);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3) cout<<0;
    else if(n==3)
    {
        if(a[1]+a[2]+a[3]>maxx(a[1],a[2],a[3])*2) cout<<1;
        else cout<<0;
    }
    else
    {
        long long cnt=0;
        for(int i=1;i<n-1;i++)
        {
            cnt+=(n-i-1)*i;
            cnt=cnt%mod;
        }
        cout<<cnt;
        return 0;
    }
}

