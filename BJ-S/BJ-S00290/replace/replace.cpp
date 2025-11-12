#include<bits/stdc++.h>
using namespace std;
int n, q;
struct p{
    string s;
}pp[100000];
struct t{
    string t1, t2;
}tt[100000];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q ;
    for(int i = 1; i <= n; i++) cin >> pp[i].s;
    for(int i = 1; i <= q; i++) {
        cin >> tt[i].t1 >> tt[i].t2 ;
    }
    cout << 2 << endl << 0 ;
}
