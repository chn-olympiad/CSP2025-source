#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
ll n, m;
char op[510];
ll a[510];
bool f;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> op[i];
        if(op[i] == 0){
            f = true;
        }
    }
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        if(a[i] == 0){
            f = true;
        }
    }
    if(m == n){
        if(!f){
            cout << 1;
        }
        else{
            cout << 0;
        }
        return 0;
    }
    if(!f){
        cout << 0;
        return 0;
    }
    for(int i = m;i <= n;i ++){
        ll num1 = 1, num2 = 1;
        for(int j = 1;j <= n - i + 1;j ++){
            num1 *= j;
        }
        for(int j = i;j <= n;j ++){
            num2 *= j;
        }
        cout << num2 / num1 % 998244353;
    }
    return 0;
}
