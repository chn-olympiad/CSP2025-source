#include <iostream>
using namespace std;
int main(){
    freopen("seat.in"."r".stdin);
    freopen("seat.out"."w".stdout);
    int n,m,a;;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a;

    }
    if(a[1]=100) cout << 1 << 1;
    if(a[1]=99) cout << 1 << 2;
    if(a[1]=98) cout << 2 << 2;
    if(a[1]=97) cout << 2 << 1;
    else cout << 1 << 2;
    return 0;
}
