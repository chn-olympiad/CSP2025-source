#include<bits/stdc++.h>
#define LL int
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    LL n,m;
    cin >> n >> m;
    LL a[15][15];
    LL nu[105],r;
    if(n == 1 && m == 1){
        cout << 1 << ' ' << 1;
    }
    for(LL i = 0;i < n * m;i++){
        cin >> nu[i];
    }
    r = nu[0];
    LL id = 0,x = 0,y = 0,p;
    sort(nu,nu + (n * m));
    for(int i = 0;i < n * m;i++){
        if(nu[i] == r){
            p = i + 1;
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            a[x][y] = id;
            id++;
            if(y % 2 == 0){
                x++;
            }
            else{
                x--;
            }
        }
        y++;
        x--;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(a[i][j] == p){
                cout << i + 1 << ' ' << j + 1;
            }
        }
    }
    return 0;
}
/*
*/