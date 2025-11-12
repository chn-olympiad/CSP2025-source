#include<bits/stdc++.h>
using namespace std;

long long n, m, vis[510], mod = 998244353, k = 1, cnt = 0;
char a[510];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        for(int j = 1; j <= x; j++){
            vis[j]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == '1' && vis[i]){
            cnt++;
        }
    }
    if(cnt < m){
        cout<<0;
        return 0;
    }
    for(int i = 1; i <= vis[1]; i++){
        k *= i;
    }
    cout<<k;
    return 0;
}