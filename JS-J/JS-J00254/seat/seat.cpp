#include<bits/stdc++.h>
using namespace std;
#define ll long long

int rd(){
    int num = 0, f = 1;
    char ch;
    ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        num = num * 10 + (ch - '0');
        ch = getchar();
    }
    return num * f;
}
constexpr ll N = 100;
ll n, m, a, s, t = 1, ans;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    n = rd(), m = rd(), a = rd();
    for(ll i = 1; i < n * m; i++){
        s = rd();
        if(s > a){
            t++;
        }
    }
    a = t / n;
    s = t % n;
    if(!s){
        if(a % 2){
            cout << a << " " << n;
        }
        else{
            cout << a << " " << 1;
        }
        return 0;
    }
    a++;
    if(a % 2){
        cout << a << " " << s;
    }
    else{
        cout << a << " " << n - s + 1;
    }
    return 0;
}