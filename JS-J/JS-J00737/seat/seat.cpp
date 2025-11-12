#include <bits/stdc++.h>
using namespace std;
int n,m,point,pai = 1,tmp,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> point;
    for(int i = 2;i <= n * m;i++){
        cin >> tmp;
        if(tmp > point) pai++;
    }
    y = pai / n;
    if(pai % n != 0) y++;
    if(y % 2 != 0){
        x = pai % n;
        if(x == 0) x = n;
    }
    else{
        tmp = (y-1)*n+1;
        x = n-(pai-tmp);
    }
    cout << y << ' ' << x;
    return 0;
}
