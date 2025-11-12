#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[101];
    for(int i=1;i<=n*m;i++){
       cin>>a[i];
    }
    if(a[1]==1){
        cout<<m<<" "<<n;
        return 0;
    }
    else if(a[1]==n*m){
        cout<<1<<" "<<1;
    }

    return 0;
}
