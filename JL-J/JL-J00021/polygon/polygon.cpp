#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
const int N = 5010;
int a[N], q[N];
long long sum = 0;
int n, pos=1;
void dfs(int x, int v[]){
    if(x == n){
        int maxn = INT_MIN;
        int sumn = 0;
        for(int i = 1; i <= pos; i++){
            if(v[pos] > maxn) maxn = v[pos];
            sumn += v[pos];
        }
        if(sumn > 2 * maxn){
            sum++;
            sum %= MOD;
            v[pos] = 0;
        }
        return;
    }
    dfs(x+1, v);
    v[pos] = 0;
    pos++;
    v[pos] = a[x];
    dfs(x+1, v);
    v[pos] = 0;
    pos--;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >>n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        q[i] = q[i-1] + a[i];
    }
    sort(a+1, a+n+1);
    bool all_1 = true;
    for(int i = 1; i <= n; i++){
        if(a[i] != 1){
            all_1 = false;
            break;
        }
    }
    if(all_1){
        for(int i = 3; i <= n; i++){
            int t_sum = 1;
            for(int j = n; j > n-i; j--){
                t_sum *= j;
                t_sum %= MOD;
            }
            for(int j = 1; j <= i; j++){
                t_sum /= j;
            }
            sum += t_sum;
        }
    }
    else{
        int v[N];
        dfs(1, v);
    }
    cout << sum;
return 0;
}
