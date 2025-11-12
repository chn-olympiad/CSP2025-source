#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

namespace Solution {
    constexpr int MAX_N = 1e5+10;
    
    int n;
    struct Person {
        int pref;
        int v1,v2;
    } p[MAX_N];

    int cnt[3],loss[3][MAX_N],ans;

    void init() {
        memset(cnt,0,sizeof(cnt));
        ans = 0;
    }

    void solve() {
        cin>>n;
        for(int i=1;i<=n;++i) {
            pii a[3];
            for(int j=0;j<3;++j) {
                cin>>a[j].first;
                a[j].second = j;
            }
            sort(a,a+3);

            p[i].pref = a[2].second;
            p[i].v1 = a[2].first;
            p[i].v2 = a[1].first;
        }

        for(int i=1;i<=n;++i) {
            cnt[p[i].pref]++;
            ans += p[i].v1;
            loss[p[i].pref][cnt[p[i].pref]] = p[i].v1-p[i].v2;

            // cout<<p[i].pref<<' '<<p[i].v1<<'\n';
        }

        for(int j=0;j<3;++j) {
            if(cnt[j]>n/2) {
                sort(loss[j]+1,loss[j]+cnt[j]+1);
                int m = cnt[j]-n/2;
                for(int i=1;i<=m;++i) {
                    ans -= loss[j][i];
                }
            }
        }

        cout<<ans<<'\n';
    }
}

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin>>T;
    for(int t=1;t<=T;++t) {
        Solution::init();
        Solution::solve();
    }
    return 0;
}