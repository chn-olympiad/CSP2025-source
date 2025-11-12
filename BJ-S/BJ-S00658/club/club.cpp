#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,a[N],b[N],c[N],mx=0;

void dfs(int id,int d1,int d2,int d3,int ans){
    if(id==n){
        if(d1<=n/2&&d2<=n/2&&d3<=n/2){
            mx=max(mx,ans);
 //           cout<<ans<<endl;
        }
        return;
    }
    dfs(id+1,d1+1,d2,d3,ans+a[id+1]);
    dfs(id+1,d1,d2+1,d3,ans+b[id+1]);
    dfs(id+1,d1,d2,d3+1,ans+c[id+1]);
}
void solve(){
    mx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    dfs(0,0,0,0,0);
    cout<<mx<<endl;
}
int main( ){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
