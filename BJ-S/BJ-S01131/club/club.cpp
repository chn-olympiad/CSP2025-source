#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][3];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            ans+=max(a[i][0],max(a[i][1],a[i][2]));
        }
        cout<<ans<<endl;
    }
    return 0;
}

