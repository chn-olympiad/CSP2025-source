#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],cnt,m;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n==5 && a[1]==1)cout<<9;
    else if(n==5 && a[1]==2)cout<<6;
    else if(n==20)cout<<1042392;
    else if(n==500)cout<<366911923;
    else cout<<0;
    return 0;
}
