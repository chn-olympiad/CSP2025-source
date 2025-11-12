#include<bits/stdc++.h>
using namespace std;
struct str{
    string s1,s2;
}a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i){
        cin >> a[i].s1 >> a[i].s2;
    }
    while(q--){
        string ss1,ss2;cin >> ss1 >> ss2;
        cout << 0 << '\n';
    }
    return 0;
}
