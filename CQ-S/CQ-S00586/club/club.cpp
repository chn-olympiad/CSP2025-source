// Problem: club - ver1 (15:00)
// Check: [freopen OK] [long long OK] [O(NlogN) OK] [Bigdata OK]
// by 1000ttank
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<vector<ll>> a(n+1,vector<ll> (4,0));
    vector<vector<int>> r(4);
    ll ans=0;
    for (int i=1;i<=n;i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if (a[i][1]>a[i][2]) {
            if (a[i][1]>a[i][3]) {
                r[1].push_back(i); ans+=a[i][1];
            } else {
                r[3].push_back(i); ans+=a[i][3];
            }
        } else {
            if (a[i][2]>a[i][3]) {
                r[2].push_back(i); ans+=a[i][2];
            } else {
                r[3].push_back(i); ans+=a[i][3];
            }
        }
    }
    int mid=n/2;
    if (r[1].size()<=mid && r[2].size()<=mid && r[3].size()<=mid) {
        cout << ans << endl; return ;
    }
    int up=-1;
    for (int i=1;i<=3;i++) if (r[i].size()>mid) up=i;
    vector<ll> d;
    for (int i:r[up]) {
        sort(a[i].begin()+1,a[i].end(),[&](int x,int y)->bool {return x>y;});
        d.push_back(a[i][1]-a[i][2]);
    }
    sort(d.begin(),d.end());
    for (int i=0;i<d.size()-mid;i++) {
        ans-=d[i];
    }
    cout << ans << endl;
}
int main() {
    #define CONTEST
    
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
/*
testData:

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0 
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/