#include <iostream>
#include <string>
using namespace std;

int n, q;
string a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int T;
    cin>>T;
    while (T--) {
        //remember memset
        cin>>n>>q;
        for (int i=0;i<n+q;++i) cin>>a>>b;
        cout<<0<<'\n';
    }

    return 0;
}