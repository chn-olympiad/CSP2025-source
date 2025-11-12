#include<bits/stdc++.h>
using namespace std;

int sa[5005];
int ans[5005];
bool vis[5005];
long long cnt = 0;
int n;

void dfs(int now, int w) {
    if(now > w) {
        for(int i = 1;i <= w;i ++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = now;i <= n;i ++) {
        if(vis[sa[i]] == 0 && sa[i]) {
            vis[sa[i]] = 1;
            ans[now] = sa[i];
            dfs(now + 1, w);
            vis[sa[i]] = 0;
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i ++) {
        scanf("%d", &sa[i]);
    }

    for(int i = 3;i <= n;i ++) {
        dfs(1, i);
    }
    cout << cnt;

    return 0;
}
