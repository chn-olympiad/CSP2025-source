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
constexpr ll N = 5e5;
ll n, k, s, r = 0, a[N + 5], ans;
map<int, pair<bool, int> > g;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = rd(), k = rd();
    g[0].first = true, g[0].second = 0;
    for(ll i = 1; i <= n; i++){
        a[i] = rd();
        a[i] ^= a[i - 1];
        s = (a[i] ^ k);
        if(g[s].first && g[s].second + 1 > r){
            ans++;
            r = i;
        }
        g[a[i]].first = true;
        g[a[i]].second = i;
    }
    cout << ans;
    return 0;
}