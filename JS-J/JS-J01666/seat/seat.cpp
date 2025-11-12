#include<bits/stdc++.h>
using namespace std;
int a[1005];
int m , n;
int k , j;
int nx , ny;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    k = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == k){
            j = i;
            break;
        }
    }
    double p = n * 1.0;
    nx = ceil(j / p);
    if(nx % 2 == 1){
        if(j % n == 0)ny = n;
        else ny = j % n;
    }
    if(nx % 2 == 0){
        if(j % n == 0)ny = 1;
        else ny = n - j % n + 1;
    }
    cout << nx << " " << ny;
    return 0;
}
