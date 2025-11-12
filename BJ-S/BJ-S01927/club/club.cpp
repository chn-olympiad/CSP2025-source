#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 5;
int n;

int a[NR][4];
int cnt[4];
bool vis[NR];
struct node{
    int v, id, d;
    bool operator <(const node &a) const{
        return v < a.v;
    }
};
priority_queue<node> q;

void solve()
{
    cin >> n;
    while(!q.empty()) q.pop();
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 3; j ++){
            cin >> a[i][j];
            q.push({a[i][j], i, j});
        }
    }
    int ans = 0;
    while(!q.empty()){
        node x = q.top();
        q.pop();
        if(vis[x.id] || cnt[x.d] == n/2) continue;
        cnt[x.d] ++, vis[x.id] = 1;
        ans += x.v;
    }
    cout << ans << '\n';
}
int bot[4], ans;
void dfs(int x, int sum){
    if(x > n){
        ans = max(ans, sum);
        return ;
    }
    for(int i =1; i <= 3; i ++){
        if(bot[i] == n/2) continue;
        bot[i] ++;
        dfs(x+1, sum + a[x][i]);
        bot[i] --;
    }

}

void solve3()
{
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= 3; j ++){
            cin >> a[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;

}


int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
        if(n <= 30) solve3();
        else solve();
    return 0;
}
