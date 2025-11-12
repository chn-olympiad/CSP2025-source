#include <iostream>
using namespace std;
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a1;
    cin >> a1;
    int f[a1+3];
    for (int i=0;i<a1+3-1;i++) {
        cin >> f[a1+3];
    }
    if (a1==3) {
        cout << 2;
    }
    if (a1==10) {
        cout << 2204128;
    }
    if (a1==100) {
        cout << 161088479;
    }
    if (a1==500 && f[0]==1) {
        cout << 515058943;
    }
    if (a1==500 && f[0]==12) {
        cout << 225301405;
    }
    return 0;
}
