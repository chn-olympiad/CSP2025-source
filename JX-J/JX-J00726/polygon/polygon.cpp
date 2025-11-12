#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
long long a[1000005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n == 3)
    {
        ans += a[1]+a[2]+a[3];
        if(a[n]*2 < ans) cout<<1<<endl;
        else cout<<0<<endl;
    }

    return 0;
}
