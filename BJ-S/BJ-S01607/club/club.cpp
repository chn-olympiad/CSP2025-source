#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,s,e) for(int i=s;i<=e;i++)
#define dfr(i,s,e) for(int i=s;i>=e;i--)
vector<int> v[4];
void solve(){
    fr(i,1,3)v[i].clear();
    int n;
    cin >> n;
    int ans=0;
    fr(i,1,n){
        int a1,a2,a3;
        cin >> a1 >> a2 >> a3;
        int mx=max(max(a1,a2),a3);
        if(a1==mx){
            ans+=a1;
            v[1].push_back(mx-max(a2,a3));
        }
        else if(a2==mx){
            ans+=a2;
            v[2].push_back(mx-max(a1,a3));
        }
        else{
            ans+=a3;
            v[3].push_back(mx-max(a1,a2));
        }
    }
    fr(i,1,3){
        if(v[i].size()>(n/2)){
            sort(v[i].begin(),v[i].end());
            int nd=(v[i].size())-(n/2);
            fr(j,1,nd)ans-=v[i][j-1];
        }
    }
    cout << ans << endl;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
