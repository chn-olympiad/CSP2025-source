#include <bits/stdc++.h>
using namespace std;
const int N=15;
string s;
int a[N];
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin>>s;
    int len=s.size();
    for (int i=0; i<=9; i++) {
        a[i]=0;
    }
    for (int i=0; i<len; i++) {
        if (s[i]>='0' && s[i]<='9') {
            a[s[i]-'0']++;
        }
    }
    if (a[9]==0 && a[8]==0 && a[7]==0 && a[6]==0 && a[5]==0 && a[4]==0 && a[3]==0 && a[2]==0 && a[1]==0) {
        cout<<0;
        return 0;
    }
    for (int i=9; i>=0; i--) {
        for (int j=1; j<=a[i]; j++) {
            cout<<i;
        }
    }
    return 0;
}
