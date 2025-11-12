#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;
ll n, m, a[N], l, r;
ll box[15][15];
bool cmp(ll a1, ll b1){
    return a1 > b1;
}
int main(){
    freopen("seat.in", "r". stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    r = a[1];
    stable_sort(a + 1, a + 1 + n * m, cmp);
    for(ll i = 1; i <= m; i++){
        if(i % 2 != 0){
            for(ll j = 1; j <= n; j++){
                box[j][i] = a[++l];
            }
        }
        else{
            for(ll j = n; j >= 1; j--){
                box[j][i] = a[++l];
            }
        }

    }
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(box[i][j] == r){
                cout << j << ' ' << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}
