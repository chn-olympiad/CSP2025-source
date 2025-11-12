#include<bits/stdc++.h>
using namespace std;
int n, a[5010], s[5010], now = 0, cnt = 0;
bool v[5010];
void dfs(int d, int r){
    if(d == now+1){
        int sum = 0;
        int maxn = -1;
        for(int i = 1; i <= now; i++){
            sum += s[i];
            maxn = max(maxn, s[i]);
        }
        if(sum > 2*maxn) cnt++;
        return ;
    }
    for(int i = r; i <= n; i++){
        if(!v[i]){
            v[i] = 1;
            s[d] = a[i];
            dfs(d+1, i);
            s[d] = 0;
            v[i] = 0;
        }
    }
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 3; i <= n; i++){
        now = i;
        dfs(1, 1);
    }
    cout << cnt;
    return 0;
}
