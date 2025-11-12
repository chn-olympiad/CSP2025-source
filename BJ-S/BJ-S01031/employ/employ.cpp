#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define maxm 105
#define maxd 262144
int n,m;
string s;
int pas[maxn];
int c[maxn];
bool sp_a = true;
bool vis[maxn];
long long ans;
long long dp[maxd][20];
int one_cnt(long long x){
    int res = 0;
    while(x){
        x = x & (x - 1);
        res++;
    }
    return res;
}
void dfs(int pos,long long cnt){
    //cout << pos << " " << cnt << endl;
    if(pos == n + 1){
        if(cnt >= m){
            ans++;
        }
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            vis[i] = true;
            if(pos - cnt - 1 < c[i] && pas[pos] == 1){
                dfs(pos + 1,cnt + 1);
            }
            else{
                dfs(pos + 1,cnt);
            }
            vis[i] = false;
        }
    }
}
int main(){
    //freopen("employ2.in","r",stdin);
    //freopen("employ2.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++){
        pas[i] = s[i - 1] - '0';
        if(pas[i] != 1){
            sp_a = false;
        }
    }
    /*for(int i = 1;i <= n;i++){
        cout << pas[i] << " ";
    }
    cout << endl;*/
    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }
    if(n <= 10){
        dfs(1,0);
        cout << ans << endl;
        return 0;
    }
    if(n <= 18){
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++){
            dp[i][0] = 0;
        }
        for(long long j = 1;j < (1 << n);j++){
            for(int i = 0;i <= n;i++){
                for(int k = 1;k <= n;k++){
                    if(((j >> (k - 1)) & 1) == 0){
                        continue;
                    }
                    long long tmp = j - (1 << k - 1);
                    if(one_cnt(j) - i < c[k] && pas[one_cnt(j)] == 1){
                        dp[i][j] += dp[i - 1][tmp];
                    }
                    else{
                        dp[i][j] += dp[i][tmp];
                    }
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        ans = 0;
        for(int i = m;i <= n;i++){
            ans += dp[i][(1 << n) - 1];
        }
        cout << ans << endl;
    }
    return 0;
}
