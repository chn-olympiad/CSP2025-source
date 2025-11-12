#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[105], sc;
bool cmp(ll n1, ll n2){return n1 > n2;}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n * m; i++) cin >> a[i];
    sc = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    ll curx = 1, cury = 1;
    for(ll i = 1; i <= n * m; i++){
        //cout << curx << ' ' << cury << endl;
        if(a[i] == sc){
            cout << curx << ' ' << cury << endl;
            return 0;
        }
        if(curx & 1){
            if(cury == n) curx++;
            else cury++;
        }else{
            if(cury == 1) curx++;
            else cury--;
        }
    }
    return 0;
}
