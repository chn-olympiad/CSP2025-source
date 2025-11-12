#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int mod = 998244353;
int n, m, num[maxn], ans, jc[maxn];
char str[maxn];
bool flag[maxn];
int jiecheng(int number){
    if(jc[number]) return jc[number];
    jc[number] = (jiecheng(number - 1) * number) % mod;
    return jc[number];
}
void dfs(int times, int alive, int died){
    if(alive == m){
        ans += jiecheng(n - times);
        return ;
    }
    if(n - died < m){
        return ;
    }
    if(times == n){
        if(alive >= m){
            ans++;
            ans = ans % mod;
        }
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(died >= num[i] && flag[i] == true){
            flag[i] = false;
            dfs(times, alive, died + 1);
            flag[i] = true;
            return ;
        }
    }
    for(int i = 1; i <= n; i++){
        if(flag[i] == true){
            if(str[times] == '0'){
                flag[i] = false;
                dfs(times + 1, alive, died + 1);
                flag[i] = true;
            }
            else{
                flag[i] = false;
                dfs(times + 1, alive + 1, died);
                flag[i] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    jc[0] = 1, jc[1] = 1;
    cin >> n >> m;
    cin >> str;
    for(int i = 1; i <= n; i++){
        flag[i] = true;
        cin >> num[i];
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}
/*10 5
1101111011
6 0 4 2 1 2 5 4 3 3*/
