#include<bits/stdc++.h>

using namespace std;

int n, m;
char s[510];
int a[501];
bool b[501];
int c[501];
int cnt;
const int P = 998244353;

inline void calc();
inline void dfs(int x, int cnt){
    c[cnt] = x;
    if(cnt == n){
        calc();
        return;
    }
    for(int i = 1; i <= n; i++)
        if(!b[i]){
            b[i] = 1;
            dfs(i, cnt + 1);
            b[i] = 0;
        }
}
inline void calc(){
    int ans = 0;
    int t = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '1'){
            if(a[c[i]] > t) ans++;
            else t++;
        }
        else t++;
    }
    if(ans >= m)
        cnt++, cnt %= P;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++){
        memset(b, 0, sizeof(b));
        b[i] = 1;
        dfs(i, 1);
    }
    printf("%d", cnt);
    return 0;
}
