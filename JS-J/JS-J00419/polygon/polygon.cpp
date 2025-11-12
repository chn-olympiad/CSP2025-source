#define MAXN 5002
#include <iostream>

using namespace std;

int n;
long long ans;
int a[MAXN], f[MAXN];
void init(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++ i)
        cin >> a[i];
    return;
}

void dfs(int s, int l, int step){
    if(step == l){
        int sum = 0, maxm = 0;
        for(int i = 1; i <= l; ++ i){
            sum += f[i];
            maxm = max(maxm, f[i]);
        }
        if(sum > (2 * maxm)){
            ans = (ans + 1) % 998244353;
        }
        return;
    }
    for(int i = s; i <= n; ++ i){
        ++ step;
        f[step] = a[i];
        dfs(i + 1, l, step);
        f[step] = 0;
        -- step;
    }
    return;
}

void solve(){
    if(n == 3){
        int sum = a[1] + a[2] + a[3];
        int maxm = max(a[1], max(a[2], a[3]));
        if(sum > (2 * maxm)){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return;
    }
    for(int i = 3; i <= n; ++ i){
        dfs(1, i, 0);
    }
    cout << ans << endl;
    return;
}

void close(){
    fclose(stdin);
    fclose(stdout);
    return;
}

int main(){
    init();
    solve();
    close();
    return 0;
}
