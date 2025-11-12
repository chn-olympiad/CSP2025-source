#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
int mod = 998244353;
const int MAXN = 5005;
int a[MAXN];
bool vis[MAXN];

void DFS(int now,int cnt,int sum,int maxn){
    if(now == n + 1){
        if(cnt >= 3 && sum > 2 * maxn){
            ans++;
            ans %= mod;
        }
        return;
    }
    vis[now] = true;
    DFS(now + 1,cnt + 1,sum + a[now],max(maxn,a[now]));
    vis[now] = false;
    DFS(now + 1,cnt,sum,maxn);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n < 3){
        cout << 0;
        return 0;
    }
    DFS(1,0,0,0);
    cout << ans;
    return 0;
}
