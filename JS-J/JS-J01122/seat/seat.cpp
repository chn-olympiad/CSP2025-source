#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, x, cnt = 1;
signed main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            int y;
            if(i == 1 && j == 1)cin>>x;
            else{
                cin>>y;
                if(y > x)cnt++;
            }
        }
    }
    int r = cnt / n + (cnt % n != 0), c;
    if(r % 2){
        if(cnt % n == 0)c = n;
        else c = cnt % n;
    }
    else{
        if(cnt % n == 0)c = 1;
        else c = n - cnt % n + 1;
    }
    cout<<r<<' '<<c;
}
