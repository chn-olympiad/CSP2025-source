#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    srand(time(0));
    int q; cin >> q >> q;
    while(q--) cout << rand()%20 << '\n';
    return 0;
}
