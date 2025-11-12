#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 5e3;
inline int read(){
    int f = 1,x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-')
            f = -1;
        c = getchar();
    }
    while(c >= '0' && c <='9'){
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f * x;
}
int n,a[N + 5];
int s[N + 5];
int C[N + 5][N + 5];
int ans;
void dfs(int x,int maxn,int dep,int sum){
    if(x == n + 1){
        if(sum > 2 * maxn)
            ans++;
        return;
    }
    for(int i = x + 1;i <= n + 1;i++){
        if(i == n + 1 && dep <= 2)
            continue;
        dfs(i,maxn,dep + 1,sum + a[i]);
    }
}
bool check(){
    for(int i = 1;i <= n;i++)
        if(a[i] != 1)
            return false;
    return true;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    C[0][0] = 1;
    for(int i = 1;i <= N;i++){
        C[i][0] = 1;
        for(int j = 1; j <= i;j++){
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            C[i][j] %= MOD;
        }
    }
    n = read();
    for(int i = 1;i <= n;i++){
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }
    sort(a + 1,a + 1 + n,greater <int> ());
    if(n <= 20 && !check()){
        for(int i = 1;i <= n;i++){
            dfs(i,a[i],1,a[i]);
        }
        cout << ans << endl;
    }else{
        for(int i = 3;i <= n;i++){
            ans += C[n][i];
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}