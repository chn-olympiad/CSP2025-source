#include<bits/stdc++.h>
using namespace std;

const int maxn = 5005;
int n, sum = 0;
long long a[maxn];

void dfs(int s, int e){
    int su = 0, maxl = 0;
    for(int i=s; i<=e; i++){
        if(a[i] > maxl) maxl = a[i];
        su += a[i];
    }
    if(su >= maxl*2) sum ++;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    cin >> n;
    if(n < 3){
        cout << 0;
        return 0;
    }
    for(int i=1; i<=n; i++) cin >> a[i];
    dfs(1, sizeof(a[i])-1);
    cout << sum;
    return 0;
}