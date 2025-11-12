#include<bits/stdc++.h>
using namespace std;
int n, m, a[101], ans=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a[1];
    for(int i = 2; i <= n*m; i++){
        cin>>a[i];
        if(a[1]<a[i]) ans++;
    }
    if(ans%n){
        cout<<ans/n+1<<" ";
        if((ans/n+1)%2==1) cout<<ans%n;
        else cout<<n-ans%n+1;
    }else{
        cout<<ans/n<<" ";
        if((ans/n)%2==1) cout<<n;
        else cout<<1;
    }
    return 0;
}
