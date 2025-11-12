#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],a1,aw,o=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    aw=1;
    for(int i=0;i<n*m-1;i++){
        cin>>a[i];
        if(a[i]>a1)
            aw++;}
    o=0;
    if(aw%n==0)
        o=aw/n;
    else
        o=aw/n+1;
    cout<<o<<" ";
    if(o%2==0)
        if(aw%n==0)
            cout<<1;
        else
            cout<<n-(aw%n)+1;
    else
        if(aw%n==0)
            cout<<n;
        else
            cout<<aw%n;
    return 0;
}
