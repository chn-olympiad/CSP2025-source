#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5000 + 10;
int a[N];

int n;
long long ans , sum;
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out", "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    if(n == 3){
       sort(a + 1 , a + n + 1);
       if(a[1] + a[2] > a[3])
            ans ++;
       cout << ans << endl;
       return 0;
    }
    return 0;
}
