//AH-J01482 Eason Cyj001001
#include "bits/stdc++.h"
#define int long long

using namespace std;
string a;
string s;

bool cmp(char a,char b) {
    return a>b;
}

signed main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    int len = a.size();
    for(int i=0; i<len; i++) {
        if(a[i] >= '0' && a[i] <= '9') {
            s += a[i];
        }
    }
    sort(s.begin(),s.end(),cmp);
    cout << s;
    return 0;
}
