//TLE 10pts
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,m;
long long cnt;
bool flag = true;
int a[505],path[505];
bool vis[505];
string s;
bool check(){
    int failed = 0;
    //for(int i = 1;i <= n;i++) cout<<path[i]<<" ";
    //cout<<"\n";
    for(int i = 1;i <= n;i++){
        int id = path[i];
        if(s[i - 1] == '0') failed++;
        else if(failed >= a[id]) failed++;
    }
    //cout<<failed<<"\n";
    return n - failed >= m;
}
void dfs(int pos){
    if(pos > n){
        if(check()) cnt++;
        cnt %= mod;
        return ;
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]) {
            vis[i] = true;
            path[pos] = i;
            dfs(pos + 1);
            vis[i] = false;
        }
    }
    return ;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '0'){
            flag = false;
            break;
        }
    }
    for(int i = 1;i <= n;i++) cin>>a[i];
    dfs(1);
    cout << cnt;
    return 0;
}
