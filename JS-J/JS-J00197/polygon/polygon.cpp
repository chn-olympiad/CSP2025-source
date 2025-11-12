#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    long long o=0;
    for(int i=n-1;i>=1;i--)
    {
        o+=i;
    }
    cout<<o;
    return 0;
}
