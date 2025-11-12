#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[120];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sc=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(sc==a[i]){
            sc=i;
            break;
        }
    }
    int l=sc/n;
    if(sc%n==0){
        if(l%2==0) cout<<l<<' '<<1;
        if(l%2==1) cout<<l<<' '<<n;
    }
    else{
        sc%=n;
        if(l%2==0) cout<<l+1<<' '<<sc;
        if(l%2==1) cout<<l+1<<' '<<n-sc+1;
    }
    return 0;
}
