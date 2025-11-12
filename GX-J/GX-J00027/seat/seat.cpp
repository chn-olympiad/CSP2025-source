#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,a[105],b;
    cin >> n >> m;
    const int nm = n*m;
    for(int i = 1;i <= nm;i++){
        cin >> a[i];
    }r = a[1];b = nm;
    sort(a+1,a+nm+1);
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(a[b] == r){cout << i << " " << j;return 0;}
            b--;
        }
        i++;
        if(i > m){break;}
        for(int j = n;j >= 1;j--){
            if(a[b] == r){cout << i << " " << j;return 0;}
            b--;
        }
    }
    return 0;
}
