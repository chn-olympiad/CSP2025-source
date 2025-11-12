#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,y;
    cin >> n >> m;
    int a[1000];
    for(int i = 1;i <= n * m;i++){cin >> a[i];}
    int s = a[1],p = 1;
    for (int i = 2;i <= n * m;i++){
        if (a[i] > s){
            p ++;
        }
    }
    int x = p % (2 * n);
    if (x <= n && x != 0){
        t = x;
    }else if(x != 0){
        t = 2*n-x + 1;
    }else t = 1;
    if (p % n == 0) {y = p/n;}
    else {y = (p / n) + 1;}
    cout << y << " " << t;
    return 0;
}
