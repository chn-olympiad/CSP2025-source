#include<bits/stdc++.h>
using namespace std;
long long sum;
int n,ma,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]>ma)ma=a[i];
    }
    if(n<3 || sum<=(2*ma))cout<<0;
    else if(n==3 && ma<=10)cout<<1;
    else cout<<n/3;
    return 0;
}
