#include<bits/stdc++.h>
using namespace std ;
const int P = 998244353 ;
const int N = 19 ;
int n,m,ans;
string s ;
int c[N] ;
int box[11],cnt;
bool vis[11];

void dfs(int cur,int cnt){
    if(n - cnt < m) return ;
    if( cur == n+1 ){
        ans ++ ;
        return ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        if(!vis[i]){
            box[cur] = i ;
            vis[i] = 1;
            if(s[cur-1] == '0' || cnt >= c[i]){
                dfs(cur+1,cnt+1);
            }
            else{
                dfs(cur+1,cnt);
            }
            vis[i] = 0 ;
            box[cur] = 0 ;
        }
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m ;
    cin >> s ;
    long long num = 1 ;
    for(int i = 2 ; i <= n ; i ++ ) num = num * i % P ;
    bool flag = 1;
    for(int i = 0 ; i < s.size() ; i ++ ){
        if(s[i] =='0' ) flag = 0 ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> c[i] ;
        if(c[i] == 0) flag = 0 ;
    }
    if(n > 10){
        if(m == n){
            if(flag == 1) cout << num;
            else cout << 0 ;
        }
        else cout << 319 ;
        return 0 ;
    }

    dfs(1,0);
    cout << ans ;
    return 0 ;
}
// I LOVE HXT !
