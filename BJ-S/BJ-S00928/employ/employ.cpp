#include <iostream>
using namespace std;

int n, m, c[505], ans=1;
char a[505];

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> a;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        ans *= c[i];
    }
    cout << ans;
    return 0;
}
