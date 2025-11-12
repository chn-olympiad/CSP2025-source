#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 5e5+10;
int n, k, a[N];
bool vis[N];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int r = 0, nxor = 0, ans = 0;
    for(int i = 1; i <= n; ++i)
        if(a[i] == k) ans++, vis[i]= 1;
    while(r <= n){
        if(vis[r+1]){r += 1, nxor = 0;continue;}
        nxor ^= a[++r];
        if(nxor == k && r <= n){ans++, r += 1, nxor = 0;continue;}
    }
    cout << ans;
    return 0;
}
