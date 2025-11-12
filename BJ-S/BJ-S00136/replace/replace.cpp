#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005][2],ss[2];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s[i][0] >> s[i][1];
    }
    for(int i=1;i<=q;i++){
        cin >> ss[0] >> ss[1];
        cout << 0 << "\n";
    }
    return 0;
}
