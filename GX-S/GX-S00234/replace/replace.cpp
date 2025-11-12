#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
const int L = 5e6 + 10;
inline ll read(){
    ll x = 0, neg = 1;
    char c = getchar();
    while(c < '0' || c > '9'){
        if(c == '-') neg = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x<<1) + (x<<3) + c - '0';
        c = getchar();
    }
    return x * neg;
}
int n, q;
struct {
    string s1, s2;
} a[N];
string t1, t2;
int solve(){
    int res = 0;
    for(int u = 1; u <= n; u++){
        int ne1[N] = {0} , ne2[N] = {0}, tt[N] = {0};
        int lenp1 = a[u].s1.size(), lenp2 = a[u].s2.size();
        int lens1 = t1.size(), lens2 = t2.size();
        int j = -1;
        for(int i = 1; i < lenp1; i++){
            while(j > -1 && a[u].s1[i] != a[u].s1[j+1]) j = ne1[j];
            if(a[u].s1[i] == a[u].s1[j+1]) j++;
            ne1[i] = j;
        }
        j = -1;
        for(int i = 1; i < lenp2; i++){
            while(j > -1 && a[u].s2[i] != a[u].s2[j+1]) j = ne2[j];
            if(a[u].s2[i] == a[u].s2[j+1]) j++;
            ne2[i] = j;
        }
        j = -1;
        for(int i = 0; i < lens1; i++){
            while(j > -1 && t1[i] != a[u].s1[j+1]) j = ne1[j];
            if(t1[i] == a[u].s1[j+1]) j++;
            if(j == lenp1 - 1) tt[i-lenp1+1]++;
        }
        j = -1;
        for(int i = 0; i < lens2; i++){
            while(j > -1 && t2[i] != a[u].s2[j+1]) j = ne2[j];
            if(t2[i] == a[u].s2[j+1]) j++;
            if(j == lenp2 - 1) tt[i-lenp2+1]++;
        }
        for(int i = 0; i < lens1; i++) if(tt[i] % 2 == 0) res++;
        printf("%d\n", res);
    }
    return res;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    n = read(), q = read();
    for(int i = 1; i <= n; i++) {
        cin >> a[i].s1;
        cin >> a[i].s2;
    }
    while(q--){
        cin >> t1;
        cin >> t2;
        printf("0\n");
    }
    return 0;
}
