#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a;
    cin >> n >> m;
    int s[100] = {};
    cin >> a;
    s[0] = a;
    for(int i = 1;i < n*m;i++){
        cin >> s[i];
    }
    sort(begin(s),end(s));
    auto l = end(s)-lower_bound(begin(s),end(s),a);
    int q = (1.0*l/n == 1*l/n ? 1*l/n : 1*l/n+1);
    int p = (l%n == 0?n:l%n);
    cout << q << ' ' << (int(q)%2 == 1 ? p : n-p+1);
    return 0;
}
