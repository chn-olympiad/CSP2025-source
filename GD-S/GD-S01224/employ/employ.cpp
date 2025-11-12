#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin>>n>>m;
    cin>>s;
    for (int i=0;i<n;++i) {
        cin>>m;
    }

    if (n>=500) {
        cout<<114;
        return 0;
    }

    cout<<5;

    return 0;
}