#include <bits/stdc++.h>
using namespace std;
int m,n;
int r,s;
int num = 0;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> r;
    for(int i = 1; i <= n*m-1; i++){
        cin >> s;
        if(s > r){
            num++;
        }
    }
    int lie = num/n+1;
    int hang;
    if(lie % 2 == 0) hang = n*lie - num;
    else hang = num-(lie-1)*n+1;
    cout << lie << ' ' << hang;
    return 0;
}
