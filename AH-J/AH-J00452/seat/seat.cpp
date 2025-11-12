#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1005];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rk=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
            rk++;
        }
    }
    int l=rk/n+(rk%n!=0);
    int r;
    if(l%2==0){
        r=n-rk%n+1;
    }
    else{
        if(rk%n==0){
            r=n;
        }
        else{
            r=rk%n;
        }
    }
    cout<<l<<' '<<r;
    return 0;
}
