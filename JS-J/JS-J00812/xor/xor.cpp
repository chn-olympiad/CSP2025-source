#include<bits/stdc++.h>
using namespace std;
int n, a[500005], b[500005][3], js, maxn;
long long k;
int ws(int x, int y){
    int cnt = 0, ans = 0;
    while (x != 0 || y != 0){
        cnt *= 2;
        if(x % 2 == 1 && y % 2 != 1) cnt += 1;
        else if (x % 2 != 1 && y % 2 == 1) cnt += 1;
        else ans++;
        x /= 2, y /= 2;
    }
    cnt *= pow(2, ans);
    return cnt;
}
void dfs(int zb, int cnt){
    if (zb == js || b[zb][2] > b[js][1]){
        maxn = max(cnt, maxn);
        return;
    }
    for (int i = zb + 1; i <= js; i++){
        if (b[i][1] > b[zb][2]) dfs(i, cnt + 1);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        int ans = a[i];
        for (int j = i; j <= n; j++){
            if (j != i) ans = ws(a[j], ans);
            if (ans == k){
                b[++js][1] = i, b[js][2] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= js; i++){
        cout << b[i][1] << " " << b[i][2] << endl;
    }
    for (int i = 1; i <= js; i++){
        if(b[i][1] > b[i - 1][2] && i > 1) break;
        dfs(i, 1);
    }
    cout << maxn;
    return 0;
}
