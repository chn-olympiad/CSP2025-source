#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 10 , mod = 998244353;
long long ans = 0;
int a[MAXN];
int n;
void dfs(int x , int sum , int cnt , int maxn){
    if(x == n + 1){
        if(cnt < 3) return ;
        if(maxn * 2 >= sum) return ;
        ans++;
        return ;
    }
    dfs(x + 1 , sum , cnt , maxn);
    dfs(x + 1 , sum + a[x] , cnt + 1 , max(maxn , a[x]));
}
long long fast(long long a , long long b , long long mod){
    long long res = 1;
    while(b){
        if(b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n ; ++i){
        cin>>a[i];
    }
    if(n <= 20){
        dfs(1 , 0 , 0 , 0);
        cout<<ans;
    }
    else{
        cout<<(fast(2 , n , mod) - 1 - n - n * (n - 1) / 2 + mod + mod + mod) % mod<<"\n";
        //cout<<fast(2 , n , mod);
    }
    return 0;
}
