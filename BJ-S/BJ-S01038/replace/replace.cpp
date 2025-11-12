#include <bits/stdc++.h>
using namespace std;
const int maxn = 2*10e5+5;
int n, q;
string s1[maxn], s2[maxn], t1[maxn], t2[maxn];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >>s1[i] >> s2[i];
    }
    for(int i = 1; i <= q; i++){
        cin >> t1[i] >> t2[i];
    }
    for(int i = 1; i <= q; i++){
        cout << 0 << endl;
    }
    return 0;
}
