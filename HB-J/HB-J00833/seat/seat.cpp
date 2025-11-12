#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,c,id=1;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]) id++;
    }
    if(id%n==0){
            c=id/n;
            cout<<id/n<<' ';
    }
    else {
            c=id/n+1;
        cout<<id/n+1<<' ';
    }
    if(c%2==1) cout<<(id%n==0?n:id%n);
    else cout<<n-id%n+1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    solve();
    return 0;
}
