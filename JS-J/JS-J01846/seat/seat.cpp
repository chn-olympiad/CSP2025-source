#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int c = n * m;
    for(int i = 1; i <= c; i++){
        cin >> a[i];
    }
    int sum = a[1], id = 0;
    sort(a + 1, a + c + 1);
    for(int i = c; i >= 1; i--){
        if(a[i] == sum){
            id = i;
            break;
        }
    }
    id = n * m - id + 1;
    int l = id / n;
    id %= n;
    if(id == 0){
        id = n;
    }else{
        l++;
    }
    int h = l % 2 ? id : n - id + 1;
    if(l % 2 == 0 && id == n){
        h = 1;
    }
    cout << l << " " << h;
    return 0;
}
