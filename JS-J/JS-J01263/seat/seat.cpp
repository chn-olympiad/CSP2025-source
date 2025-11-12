#include<bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<ll,ll>
using namespace std;
const int N = 114;
int n, m, a[N], st[12][12];
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> a[i];
    int tmp = a[1];
    sort(a+1, a+n*m+1);
    reverse(a+1, a+n*m+1);
    int cur = 0;
    for(int i = 1; i <= n; i+=2){
        for(int j = 1; j <= m; j++) st[i][j] = ++cur;
        if(i+1 <= n) for(int j = m; j >= 1; j--) st[i+1][j] = ++cur;
    }
    int pos;
    for(int i = 1; i <= n*m; i++) if(a[i] == tmp) pos = i;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            if(st[i][j] == pos){
                cout << i << " " << j << "\n";
                return ;
            }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    solve();
    return 0;
}
//chennie bless me!
//Cubber bless me!
//tourist bless me!
//jlangly bless me!
//dtl