#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    string a;
    int c=0,r=0;
    cin >> n >> m;
    if (n * m >= 100){
        cout << "error";
    }
    for (int i = 0;i <= n * m;i++){
        cin >> a;
    }
    int R = a[0];
    cout << c << ' ' << r << endl;
    return 0;
}
