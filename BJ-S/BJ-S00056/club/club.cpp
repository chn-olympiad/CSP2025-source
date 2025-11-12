#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 100005;
int n, a[N][4], cnt[4], ch[N];

void solve(){
    priority_queue<int, vector<int>, greater<int> > pq;
    int ans = 0;
    cnt[1] = cnt[2] = cnt[3] = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][1] > a[i][2] && a[i][1] > a[i][3])
            ans += a[i][1], ch[i] = 1, ++cnt[1];
        else if(a[i][2] > a[i][1] && a[i][2] > a[i][3])
            ans += a[i][2], ch[i] = 2, ++cnt[2];
        else
            ans += a[i][3], ch[i] = 3, ++cnt[3];
    }
    int mst, oth1, oth2;
    if(cnt[1] > cnt[2] && cnt[1] > cnt[3])
        mst = 1, oth1 = 2, oth2 = 3;
    else if(cnt[2] > cnt[1] && cnt[2] > cnt[3])
        mst = 2, oth1 = 1, oth2 = 3;
    else
        mst = 3, oth1 = 1, oth2 = 2;
    for(int i = 1; i <= n; i ++)
        if(ch[i] == mst)
            pq.push(a[i][mst] - max(a[i][oth1], a[i][oth2]));
    while(cnt[mst] > (n / 2)){
        ans -= pq.top();
        pq.pop();
        --cnt[mst];
    }
    cout << ans << endl;
    return;
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
