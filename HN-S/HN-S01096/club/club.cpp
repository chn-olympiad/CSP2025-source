#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
template<typename T> inline void chkmax(T& x,T y){ (x < y) && (x = y); }
template<typename T> inline void chkmin(T& x,T y){ (x > y) && (x = y); }
namespace my {
    const int N = 100005;
    int n;
    int a[N][3];
    priority_queue<int,vector<int>,greater<int>> Q[3];
    inline void main(){
        cin >> n;
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            int mx = 0;
            for(int j = 0;j < 3;j++) cin >> a[i][j],chkmax(mx,a[i][j]);
            if(a[i][0] == mx) Q[0].push(min(mx - a[i][1],mx - a[i][2]));
            else if(a[i][1] == mx) Q[1].push(min(mx - a[i][0],mx - a[i][2]));
            else Q[2].push(min(mx - a[i][0],mx - a[i][1]));
            ans += mx;
        }
        int id = -1;
        for(int i = 0;i < 3;i++) if(Q[i].size() > (n >> 1)) id = i;
        if(id == -1) cout << ans << "\n";
        else {
            while(Q[id].size() > (n >> 1)) ans -= Q[id].top(),Q[id].pop();
            cout << ans << "\n";
        }
        for(int i = 0;i < 3;i++)
            while(Q[i].size()) Q[i].pop();
        return ;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t; cin >> t;
    while(t --) my::main();
    return 0;
}
/*
g++ club.cpp -o club -std=c++14 -O2 -static
time ./club
*/