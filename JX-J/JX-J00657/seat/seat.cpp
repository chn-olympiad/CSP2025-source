#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool tmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
}
    int R = a[1],w;
    sort(a+1,a+n*m+1,tmp);
    for(int i = 1;i <= n*m;i++){
        if(a[i] == R){
            w = i;
    }
}
    int c = ceil(w/n*1.0);
    cout << c << " ";
    if(c % 2 == 1){
        cout << w-(c-1)*n;
}
    if(c % 2 == 0){
        cout << n - (w-(c-1)*n) + 1;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
