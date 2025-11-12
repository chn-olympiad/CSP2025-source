#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,cnt[3],a[N][3];
priority_queue<int> q[3];
inline void file(){freopen("club.in","r",stdin),freopen("club.out","w",stdout);}
inline bool cmp(priority_queue<int> a,priority_queue<int> b){return a.size()>b.size();}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> t;
    while(t--){
        cin >> n,ans=0,memset(cnt,0,sizeof(cnt));
        while(q[0].size()) q[0].pop();
        while(q[1].size()) q[1].pop();
        while(q[2].size()) q[2].pop();
        for(int i(1);i<=n;++i){
            for(int j(0);j<3;++j) cin >> a[i][j];
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) ans+=a[i][0],++cnt[0],q[0].push(-min(a[i][0]-a[i][1],a[i][0]-a[i][2]));
            else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) ans+=a[i][1],++cnt[1],q[1].push(-min(a[i][1]-a[i][0],a[i][1]-a[i][2]));
            else ans+=a[i][2],++cnt[2],q[2].push(-min(a[i][2]-a[i][1],a[i][2]-a[i][0]));
        }
        if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2){cout << ans << '\n';continue;}
        sort(q,q+3,cmp);
        while(q[0].size()>n/2) ans+=q[0].top(),q[0].pop();
        cout << ans << '\n';
    }
    return 0;
}