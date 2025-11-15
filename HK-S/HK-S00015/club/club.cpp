#include <bits/stdc++.h>
using namespace std;
#define int long long

int T, N, vis[5], cnt[5];
int maxn = -1;

struct node{
    int a, b, c;
}A[100005];

bool cmp(node x, node y){
    return x.a > y.a;
}

void dfs(int pos){
    for (int i = 1; i <= 3; i++) if (cnt[i] > N/2) return;
    if (pos == N+1){
        int sum = 0;
        for (int i = 1; i <= N; i++){
            if (vis[i] == 1) sum += A[i].a;
            else if (vis[i] == 2) sum += A[i].b;
            else if (vis[i] == 3) sum += A[i].c;
        }
        maxn = max(sum, maxn);
        return;
    }
    vis[pos] = 1;
    cnt[1]++;
    dfs(pos + 1);
    cnt[1]--;

    vis[pos] = 2;
    cnt[2]++;
    dfs(pos + 1);
    cnt[2]--;

    cnt[3]++;
    vis[pos] = 3;
    dfs(pos + 1);
    cnt[3]--;
}

int32_t main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--){
        cin >> N;
        bool f = 1;
        for (int i = 1; i <= N; i++){
            cin >> A[i].a >> A[i].b >> A[i].c;
            if (A[i].b != 0 || A[i].c != 0) f = 0;
        }
        if (f){
            sort(A+1, A+N+1, cmp);
            int sum = 0;
            for (int i = 1; i <= N/2; i++){
                sum += A[i].a;
            }
            cout << sum << "\n";
            continue;
        }
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        maxn = -1;
        dfs(1);
        cout << maxn << "\n";
    }
    

    return 0;
}