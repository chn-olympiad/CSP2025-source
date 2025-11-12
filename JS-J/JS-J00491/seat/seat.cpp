#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
int a[N];
int n , m;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; ++i){
            cin >> a[i];
    }
    int x = a[1];
    sort(a + 1 , a + m * n + 1);
    int c = 1 , r = 1;
    for(int i = n * m; i >= 1; --i){
        if(x == a[i]){
            cout << c << " " << r << endl;
            break;
        }
        if(c % 2 == 1){
           r++;
        }else{
            r--;
        }
        if(r < 1){
            r = 1;
            c++;
        }
        if(r > n){
            r = n;
            c++;
        }
    }
    cout << endl;
    return 0;
}
