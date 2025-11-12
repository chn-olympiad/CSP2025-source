#include<bits/stdc++.h>
using namespace std;
int j01[100001], j02[100001], j03[100001], a[100001][3], ans = 0, n;
struct str1{int id, x;};
struct str{str1 b[4]; int id;} f[100001];
int cnt[4];
bool all0_3, all0_2;
bool cmp(int x, int y){return x > y;}
void dfs(int step, int sum){
    if(cnt[1]>n/2) return;
    if(cnt[2]>n/2) return;
    if(cnt[3]>n/2) return;
    if(step>n){
        ans = max(ans, sum);
        return;
    }
    for(int i = 1; i <= 3; i++){
        cnt[i]++;
        dfs(step+1, a[step][i]+sum);
        cnt[i]--;
    }
}
bool cmp1(str1 x, str1 y){
    if(x.x != y.x) return x.x > y.x;
    return x.id > y.id;
}
bool cmp2(str x, str y){
    for(int i = 1; i <= 3; i++){
        if(x.b[i].x != y.b[i].x) return x.b[i].x > y.b[i].x;
    }
    return x.b[3].id < y.b[3].id;
}
void Main(){
    memset(a, 0, sizeof a);
    memset(f, 0, sizeof f);

    cin >> n;
    all0_2 = 1, all0_3 = 1;
    bool with0 = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
            f[i].b[j].x = a[i][j];
            f[i].b[j].id = j;
            if(j == 1) j01[i] = a[i][j];
            if(j == 2) j02[i] = a[i][j];
            if(j == 3) j03[i] = a[i][j];
            if(a[i][j] != 0 && j == 3) all0_3 = 0;
            if(a[i][j] != 0 && j == 2) all0_2 = 0;
            if(a[i][j] == 0) with0 = 1;
        }
        f[i].id = i;
        sort(f[i].b+1, f[i].b+4, cmp1);
    }
    sort(f+1, f+n+1, cmp2);
    ans = 0;
    memset(cnt, 0, sizeof cnt);
    if(all0_3 != 0 && all0_2 != 0){
        sort(j01+1, j01+n+1, cmp);
        ans = 0;
        for(int i = 1; i <= n/2; i++) ans += j01[i];
        cout << ans;
        return;
    }
    memset(cnt, 0, sizeof cnt);
    if(n >= 30){
        ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                int id = f[i].b[j].id;
                if(cnt[id] < n/2){
                    cnt[id]++;
                    ans += f[i].b[j].x;
                    break;
                }
            }
        }
        cout << ans << endl;
        return;
    }
    memset(cnt, 0, sizeof cnt);
    dfs(1, 0);
    cout << ans << endl;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) Main();
    return 0;
}
