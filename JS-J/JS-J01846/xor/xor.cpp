#include<bits/stdc++.h>
using namespace std;
int a[500010];
bool v[500010];
int n, k, sum = 0, ans = 0;
void f(int i){
    for(int j = i + 1; j <= n; j++){
        if(v[j]){
            break;
        }
        sum ^= a[j];
        if(sum == k){
            ans++;
            for(int l = i; l <= j; l++){
                v[l] = 1;
            }
            break;
        }
    }
    return;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v[i] = 0;
        if(a[i] == k){
            v[i] = 1;
            ans++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!v[i]){
            sum = a[i];
            f(i);
        }
    }
    cout << ans;
    return 0;
}
