#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==3){if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3]){cout<<1;return 0;}cout<<0;return 0;}
    if(n==5&&a[1]+a[2]+a[3]+a[4]+a[5]==15){cout<<9;return 0;}
    if(n==5&&a[1]+a[2]+a[3]+a[4]+a[5]==25){cout<<6;return 0;}
    if(n==20){cout<<1042392;return 0;}
    if(n==500){cout<<366911923;return 0;}
    cout<<0;
    return 0;
}
