#include <iostream>
#include <fstream>

using namespace std;
int n, m, a, b, cnt = 1;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> a;
    for(int i = 1; i < n * m; ++i){
        cin >> b;
        if( b > a )++cnt;
    }
    int x, f = (cnt - 1) / n + 1;
    if( f % 2 ){
        x = cnt % n;
        if( x == 0 ) x += n;
    }else {
        x = (n * m - cnt + 1) % n;
        if( x == 0 ) x += n;
    }
    cout << f << ' ' << x << '\n';
    return 0;
}
