#include<bits/stdc++.h>
using namespace std;
struct od{
    int a, b, c;
    int xza;
};
od s[100010];
bool mycmp(od x, od y){
    if(x.a > y.a){
        return true;
    }
    return false;
}
int T;
int n;
int f[100010];
int cnt[10];
int maxn = 0;
int dp[100010];
void dfs(int op){
    if(op > n){
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cnt[f[i]]++;
            if(f[i] == 1){
                ans += s[i].a;
            }
            else if(f[i] == 2){
                ans += s[i].b;
            }
            else if(f[i] == 3){
                ans += s[i].c;
            }
        }
        if(cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2){
            maxn = max(maxn, ans);
        }
        return ;
    }
    for(int i = op; i <= n; i++){
        f[i] = 1;
        dfs(i + 1);
        f[i] = 2;
        dfs(i + 1);
        f[i] = 3;
        dfs(i + 1);
        f[i] = 0;
    }
    return ;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> s[i].a >> s[i].b >> s[i].c;
            if(s[i].b == 0 && s[i].c == 0){
                s[i].xza = 1;
            }
            else{
                s[i].xza = 0;
            }
        }
        int flag = 1;
        for(int i = 1; i <= n; i++){
            if(s[i].xza == 0){
                flag = 0;
            }
        }
        if(flag == 1){
            sort(s + 1, s + n + 1, mycmp);
            int ans = 0;
            for(int i = 1; i <= n / 2; i++){
                ans += s[i].a;
            }
            cout << ans;
        }
        else{
            maxn = 0;
            memset(f, 0, sizeof(f));
            dfs(1);
            cout << maxn;
        }
        cout << endl;
    }
    return 0;
}
