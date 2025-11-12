#include <bits/stdc++.h>
using namespace std;
int n,m,r,z=1;
string s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    for (int i=2;i<=n*m;i++){
        int a;
        cin>>a;
        if (a>r) z++;
    }
    int l=ceil(z*1.0/n);
    cout<<l<<' ';
    if (l%2){
        if (z%n==0) cout<<n;
        else cout<<z%n;
    }
    else{
        if (z%n==0) cout<<1;
        else cout<<n+1-z%n;
    }
    return 0;
}
