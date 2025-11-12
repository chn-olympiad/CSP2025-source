#include <bits/stdc++.h>
using namespace std;

struct st{
    int u, v, w;
}e[2000001];
bool operator <(const st &a, const st &b){
    return a.w < b.w;
}
int h[100000], a[50];
int head(int x){
    return (h[x] == x ? x : h[x] = head(h[x]));
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int cnt = n;
    for(int i = 1; i <= k; i++){
        cin >> a[i];
        cnt++;
        for(int j = 1; j <= n; j++){
            m++;
            e[m].u = j;
            e[m].v = cnt;
            cin >> e[m].w;
        }
    }
    long long ans = 9e18;
    sort(e + 1, e + m + 1);
    for(int i = 0; i < (1 << k); i++){
        for(int i = 1; i <= cnt; i++){
            h[i] = i;
        }
        int c = n - 1;
        long long res = 0;
        for(int j = 0; j < k; j++){
            if(i & (1 << j)){
                c++;
                res += a[j + 1];
            }
        }
        for(int j = 1; j <= m && c; j++){
            int u = e[j].u, v = e[j].v, w = e[j].w;
            if(v > n && !(i & (1 << (v - n - 1)))){
                continue;
            }
            if(head(u) != head(v)){
                c--;
                res += w;
                h[h[u]] = h[v];
            }
        }
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}