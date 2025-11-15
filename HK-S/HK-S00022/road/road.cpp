#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(),a.end()
int t,n,m,k,ans,x,xx,y;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x>>xx>>y;
            ans+=y;
        }
        cout<<ans<<endl;
    }
    return 0;
}
