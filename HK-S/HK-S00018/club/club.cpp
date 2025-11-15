#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int n; cin>>n;
    vector<vector<int>> a(n);
    for (int i=0;i<n;i++) {
        a[i].resize(3);
        for (int j=0;j<3;j++) cin>>a[i][j];
    }
    map<int,vector<pair<int,int>>> mp;
    vector<int> diff;
    for (auto i:a) {
        vector<int> tem=i;
        sort(tem.begin(),tem.end());
        diff.push_back(tem[2]-tem[1]);
    }
    auto maxv=[&](const vector<int> &x) {
        vector<int> tem=x;
        sort(tem.begin(),tem.end());
        return tem[2];
    } ;
    vector<int> cnt(3,0);
    for (int i=0;i<n;i++) {
        int m=maxv(a[i]);
        for (int j=0;j<3;j++) {
            if (a[i][j]==m) {
                mp[j].push_back(make_pair(diff[i],m));
                cnt[j]++;
                break;
            }
        }
    }
    ll ans=0;
    for (auto i:mp) {
        for (auto j:i.second) {
            ans+=j.second;
        }
    }
    for (int i=0;i<3;i++) {
        if (cnt[i]>(n/2)) {
            sort(mp[i].begin(),mp[i].end());
            int more=cnt[i]-(n/2);
            for (int j=0;j<more;j++) ans-=mp[i][j].first;
        }
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while (T--) solve();
    return 0;
}