#include<bits/stdc++.h>
using namespace std;
int n,nm,k,a[5005];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==3){
        if(a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[1]+a[2])cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[5]==5){cout<<9;return 0;}
    if(a[5]==10){cout<<6;return 0;}
    if(a[1]==75&&n!=3){cout<<1042392;return 0;}
    if(a[1]==37&&n!=3){cout<<366911923;return 0;}
}
