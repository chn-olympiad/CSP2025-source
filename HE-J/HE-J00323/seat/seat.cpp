#include <bits/stdc++.h>
using namespace std;

bool cmd(int a,int b){
    if(a < b) return false;
    else return true;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n*m],r = 0,b = 0,x = 0,y = 0,c = 0;
    for(int i = 0;i < n*m;i++){
        cin >> a[i];
        if(i == 0){
            r = a[i];
        }
    }
    sort(a,a+n*m,cmd);
    b = a[0];
    c = b - r;
    x = c / n + 1;
    if(x%2 == 0){
        y = m - c % n;
    }else{
        y = c % n + 1;
    }
    cout << x << " " << y;
    return 0;
}
