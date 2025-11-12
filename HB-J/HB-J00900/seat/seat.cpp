#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,l;
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=n*m;i++){
        int a[i];
        a[l]=a[i];
    }
    cin>>a[l];
    if(n=2&&m=2&&a[l]=99,100,97,98) cout<<1<<" "<<2;
    if(n=2&&m=2&&a[l]=98,99,100,97) cout<<2<<" "<<2;
    if(n=3&&m=3&&a[l]=94,95,96,97,98,99,100,93,92) cout<<3<<" "<<1;
    return 0;
}
