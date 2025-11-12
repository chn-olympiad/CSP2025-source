#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
ll n, m, s[15][15], a[105], t, r, x, y;
bool cmp(ll a, ll b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    t = n * m;
    cin >> a[1];
    r = a[1];
    for(ll i = 2; i <= t; i++){
        cin >> a[i];
    }
    x = 1, y = 1;
    sort(a + 1, a + t + 1, cmp);
    s[1][1] = a[1];
    if(a[1] == r){
        cout << 1 << " " << 1;
        return 0;
    }
    for(int i = 2; i <= t; i++){
        if(y % 2 == 1 && x == n){
            y++;
            s[x][y] = a[i];
        }
        else{
            if(y % 2 == 1){
                x++;
                s[x][y] = a[i];
            }
            else{
                if(y % 2 == 0 && x == 1){
                    y++;
                    s[x][y] = a[i];
                }
                else{
                    if(y % 2 == 0){
                        x--;
                        s[x][y] = a[i];
                    }
                }
            }
        }

        if(a[i] == r){
            cout << y << " " << x;
            break;
        }
    }
    return 0;
}
