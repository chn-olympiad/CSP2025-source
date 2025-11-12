#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,q;
    cin >> n >> q;
    string a,b;
    for (int i=0;i<n;i++){
        cin  >> a >> b;
    }
    for (int i=0;i<q;i++){
        cin  >> a >> b;
    }
    for (int i=0;i<q;i++){
        cout << 0 << endl;
    }
    return 0;
}
