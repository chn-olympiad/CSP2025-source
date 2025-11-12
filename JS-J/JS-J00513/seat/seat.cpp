#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[550];
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n*m;i ++){
        cin >> a[i];
    }
    int xr = a[0];
    sort(a,a+n*m);
    reverse(a,a+n*m);
    for(int i = 0;i < n*m;i ++){
        if(a[i] == xr){
            xr = i;
            break;
        }
    }
    //cout << xr << endl;
    int x=1,y=1;
    int f = 1;
    while(xr--){
        x += f;
        if(x == 0||x == n + 1){
            y ++;
            f = -f;
            x += f;
        }
        //cout << x << " " << y << endl;
    }
    cout << y << " " << x << endl;
    return 0;
}
