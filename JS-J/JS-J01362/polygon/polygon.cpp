#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,a[5005]={ },s[5000]={ },cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++)
    {
        long long jia=1;
        for(int j=1;j<=i;j++)jia*=(n-j+1);
        for(int j=1;j<=i;j++)jia/=j;
        cnt+=jia;
    }
    cout<<cnt%998244353;
    return 0;
}
