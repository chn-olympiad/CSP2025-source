#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset <int> st[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while (t--){
        int n,ans=0; cin>>n;
        st[0].clear();
        st[1].clear();
        st[2].clear();
        for (int i=1; i<=n; i++){
            int a,b,c; cin>>a>>b>>c;
            if (a>=b&&a>=c){
                st[0].insert(min(a-b,a-c)); ans+=a;
            }
            else if (b>=a&&b>=c){
                st[1].insert(min(b-a,b-c)); ans+=b;
            }
            else{
                st[2].insert(min(c-a,c-b)); ans+=c;
            }

        }
        while (st[0].size()>n/2){
            ans-=(*(st[0].begin()));
            st[0].erase(st[0].begin());
        }
        while (st[1].size()>n/2){
            ans-=(*(st[1].begin()));
            st[1].erase(st[1].begin());
        }
        while (st[2].size()>n/2){
            ans-=(*(st[2].begin()));
            st[2].erase(st[2].begin());
        }
        cout<<ans<<"\n";
    }
}
