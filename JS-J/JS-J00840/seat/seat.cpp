#include <bits/stdc++.h>
using namespace std;
int n,m,a[102],s,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(s==a[i]){
            ans=n*m+1-i;
            break;
        }
    }
    if(ans%(2*n+1)<=n){
        cout<<ans/(2*n+1)*2+1<<" "<<ans%(2*n);
    }else{
        cout<<ans/(2*n+1)*2+2<<" "<<2*n+1-(ans%(2*n+1));
    }

    return 0;
}
