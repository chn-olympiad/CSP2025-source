#include<bits/stdc++.h>
using namespace std;
#define rep(i,t1,t2,t3) for(int i=(t1);i<=(t2);i+=(t3))
#define PII pair<int,int>
#define fi first
#define se second
constexpr int N=100010;
int n,a[N][3],b[N];
inline void solve(){
    cin>>n;
    vector<int> t[3];
    rep(i,1,n,1){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]) t[0].push_back(i);
        else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]) t[1].push_back(i);
        else t[2].push_back(i);
    }
    int ans=0;
    for(auto i:t[0]) ans+=a[i][0];
    for(auto i:t[1]) ans+=a[i][1];
    for(auto i:t[2]) ans+=a[i][2];
    if(t[0].size()<=n/2 && t[1].size()<=n/2 && t[2].size()<=n/2){
        cout<<ans<<'\n';
        return;
    }
    auto work=[&](int x){
        rep(i,1,n,1) b[i]=0;
        vector<PII> tmp;
        for(auto i:t[x])
            rep(j,0,2,1){
                if(x!=j) tmp.push_back(make_pair(a[i][x]-a[i][j],i));
            }
        sort(tmp.begin(),tmp.end());
        int tot=t[x].size();
        for(auto i:tmp){
            if(b[i.se]) continue;
            tot--,ans-=i.fi,b[i.se]=1;
            if(tot==n/2) break;
        }
    };
    rep(i,0,2,1) if(t[i].size()>n/2){work(i);break;}
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
