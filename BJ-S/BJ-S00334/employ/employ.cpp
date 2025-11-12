#include <iostream>
using namespace std;
int n,m;
string b;
int wk[550];
int put[550];
long long ans = 0;
const int mod = 998244353;
bool vis[550] = {0};
bool check(){
    int run = 0;
    for(int o = 1;o <= n;o++){
        if(b[o - 1] == '0' || run >= wk[put[o]]){
                //cout << b[o - 1] << " run:" << o << " ";
            run++;
        }
    }
    //cout << endl << endl;
    if(n - run >= m){
        return true;
    }
    return false;
}
void dfs(int lvl){
    if(lvl > n){
        if(check()){
            ans++;
            ans %= mod;
        }
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            vis[i] = true;
            put[lvl] = i;
            dfs(lvl + 1);
            vis[i] = false;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    int t = n;
    cin >> b;
    bool spa;
    if(b.find('0') == string::npos){
        spa = true;
    }
    else{
        spa = false;
    }
    for(int i = 1;i <= n;i++){
        cin >> wk[i];
        if(wk[i] == 0){
            t--;
        }
    }
    if(spa){
        long long c = 1;
        for(int i = 2;i <= t;i++){
            c *= i;
            c %= mod;
        }
        cout << c;
    }
    else{
        dfs(1);
        cout << ans;
    }
    return 0;
}
