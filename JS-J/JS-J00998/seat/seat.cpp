#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[110];
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second > b.second) return 1;
    else return 0;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i].second;
        a[i].first = i;
    }
    sort(a + 1, a + n * m + 1, cmp);
    for(int i = 1; i <= n * m; i++){
        if(a[i].first == 1){
            int x = i % n;
            int y = i / n;
            if(x > 0) y += 1;
            if(x == 0) x = n;
            bool c = 0;
            if(y % 2 == 0) c = 1;
            if(c){
                cout << y << ' ' << (n - x) + 1 << endl;
                return 0;
            }
            else{
                cout << y << ' ' << x << endl;
                return 0;
            }
        }
    }
    cout << 1 <<' ' << 1 << endl;
    return 0;
}