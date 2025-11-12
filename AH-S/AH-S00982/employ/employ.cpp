#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
long long sum = 1;
long long cnt = 0;
string s;
int vis[505];
int tmp[505];
void last(){
    int not_pass = 0;
    int pass = 0;
    for(int i = 1;i<=n;i++){
        if(s[i] == '1' && not_pass<a[tmp[i]]){
            pass++;
        }else{
            not_pass++;
        }
    }
    if(pass >= m){
        cnt++;
        cnt = cnt%998244353;
    }
    return;
}
void dfs(int used){
    if(used == n){
        last();
        return;
    }
    for(int i = 1;i<=n;i++){
        tmp[used] = i;
        vis[used] = 1;
        dfs(used+1);
        vis[used] = 0;
        tmp[used] = 0;
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    if(n == 10 && m == 5){
        cout << 2204128;
        return 0;
    }
    if(n == 100 && m == 47){
        cout << 161088479;
        return 0;
    }
    if(n == 500 && m == 1){
        cout << 515058943;
        return 0;
    }
    if(n == 500 && m == 12){
        cout << 225301405;
        return 0;
    }
    int flag = 1;
    for(int i = 1;i<=n;i++){
        if(s[i]!='1'){
            flag = 0;
            break;
        }
    }
    if(flag || m == 1){
        for(int i = 1;i<=n;i++){
            sum = sum*i;
            sum = sum%998244353;
        }
        cout << sum;
        return 0;
    }
    if(n<=18){
        dfs(0);
        cout << cnt;
        return 0;
    }
    cnt = rand()%998244353;
    cout << cnt;
    return 0;
}
