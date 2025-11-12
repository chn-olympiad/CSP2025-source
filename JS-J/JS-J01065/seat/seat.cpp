#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    int p;cin>>p;int ans=0;
    for(int i=1;i<n*m;i++){
        int x;cin>>x;
        if(x>p){
            ans++;
        }
    }
    cout<<ans/n+1<<' ';
    if(ans/n%2)cout<<n-ans%n;
    else cout<<ans%n+1;
    return 0;
}
