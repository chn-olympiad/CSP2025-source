#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){return x > y;}
int n, m;
int a[200];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int s = n * m;
    for(int i = 1; i <= s; i++){
        cin >> a[i];
    }
    int r = a[1], d;
    sort(a + 1, a + s + 1, cmp);
    for(int i = 1; i <= s; i++){
        if(a[i] == r){
            d = i;
            break;
        }
    }
    int t = d % n, c = d / n;
    if(t == 0){
        if(c % 2 == 1)r = n;
        else r = 1;
    }
    else {
        c += 1;
        if(c % 2 == 1)r = t;
        else r = n + 1 - t;
    }
    cout << c << ' ' << r << endl;
    return 0;
}
