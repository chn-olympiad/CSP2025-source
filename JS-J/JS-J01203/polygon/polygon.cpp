#include <bits/stdc++.h>
using namespace std;

int n,a[5005];
long long ans;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i],ans+=a[i];
    printf("%lld",998224353%ans);
    return 0;
}









