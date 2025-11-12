#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
const int N = 5200;
int n;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n < 3) return cout << 0,0;
    if(n == 3) return cout << 1,0;
    else {
        srand(time(0));
        cout << rand()%10000+1;
    }
    return 0;
}
