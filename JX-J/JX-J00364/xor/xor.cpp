#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, k, cnt, ans;
int a[maxn], sum[maxn];
struct edge{
    int l, r;
}e[maxn];
bool cmp(edge a, edge b){
    if(a.l == b.l)return (a.r - a.l + 1) < (b.r - b.l + 1);
    return a.l < b.l;
}
void dfs(int i, int t, int sum){
    if(i > n){
        ans = max(ans, sum);
        return ;
    }
    dfs(i + 1, t, sum);
    if(t < e[i].r)dfs(i + 1, e[i].r, sum + 1);
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] ^ a[i];
    }if(k == 1){
        for(int i = 1;i <= n;i++){
            if(a[i] == 1)cnt++;
        }printf("%d", cnt);
    }
    if(k == 0){
        for(int i = 1;i <= n;i++){
            if(a[i] == 0)cnt++;
        }printf("%d", cnt);
    }
    for(int i = 1;i <= n;i++){
        for(int j = i ;j <= n;j++){
            int tmp = sum[j] ^ sum[i - 1];
            if(tmp == k){
                cnt++;
                e[cnt].l = i;
                e[cnt].r = j;
            }
        }
    }
    sort(e + 1, e + cnt + 1, cmp);
    int t = 0;
    dfs(1, 0, 0);
    printf("%d", ans);
    return 0;
}
