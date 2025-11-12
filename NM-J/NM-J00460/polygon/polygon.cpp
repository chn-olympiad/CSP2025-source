#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef OFFLINE_JUDGE
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
#else
freopen("/home/noi/J/polygon/polygon8.in","r",stdin);
freopen("/home/noi/J/polygon/polygon8.out","w",stdout);
#endif // OFFLINE_JUDGE
    int n;
    cin>>n;
    int a[3];
    cin>>a[0>>a[1]>>a[2];
    sort(a,a+3);
    cout<<(a[0]+a[1])>a[2];
    return 0;
}
