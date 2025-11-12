#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;

int T, n, a[maxn][3], mx1[maxn], mx2[maxn], cnt[maxn], ans;
priority_queue<int, vector<int>, greater<int>> q;

void solve(){
    cin >> n;
    cnt[0] = cnt[1] = cnt[2] = ans = 0;
    for(int i = 1; i <= n; i++){
        mx1[i] = mx2[i] = 0;
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
            if(a[i][j] > a[i][mx1[i]]) mx1[i] = j;
        }
        if(mx1[i] == 0) mx2[i] = (a[i][1] >= a[i][2] ? 1 : 2);
        else if(mx1[i] == 1) mx2[i] = (a[i][0] >= a[i][2] ? 0 : 2);
        else mx2[i] = (a[i][0] >= a[i][1] ? 0 : 1);
        // cerr << mx1[i] << ' ' << mx2[i] << endl;
        cnt[mx1[i]]++, ans += a[i][mx1[i]];
    }
    // cerr << endl;
    if(max({cnt[0], cnt[1], cnt[2]}) <= n / 2) return cout << ans << '\n', void();
    int id = 0;
    if(cnt[1] > cnt[id]) id = 1;
    if(cnt[2] > cnt[id]) id = 2;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n; i++){
        if(mx1[i] != id) continue;
        q.push(a[i][mx1[i]] - a[i][mx2[i]]);
    }
    while(!q.empty() && cnt[id] > n / 2){
        ans -= q.top(), q.pop();
        cnt[id]--;
    }
    cout << ans << '\n';
}

int main(){
	// freopen("D:/down/club/club5.in", "r", stdin);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--) solve();
    return 0;
}