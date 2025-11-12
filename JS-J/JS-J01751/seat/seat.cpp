#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> nex_t(pair<int, int> now){
    int x = now.first, y = now.second;
    if (y % 2 != 0){
        if (x != n){
            return make_pair(x+1, y);
        }else{
            return make_pair(x, y+1);
        }
    }else{
        if (x != 1){
            return make_pair(x-1, y);
        }else{
            return make_pair(x, y+1);
        }
    }
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int a[n*m+1];
    for (int i=1; i<n*m+1; i++){
        cin >> a[i];
    }
    int temp = a[1], c = 0;
    for (int i=2; i<n*m+1; i++){
        if (a[i] > temp) c++;
    }
    pair<int, int> s;
    s.first = 1;
    s.second = 1;
    for (int i=0; i<c; i++){
        s = nex_t(s);
    }
    cout << s.second << " " << s.first;
    return 0;
}
