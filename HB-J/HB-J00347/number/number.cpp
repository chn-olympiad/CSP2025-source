#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15;
string x;
int book[N];
signed main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>x;
    for(char c:x) {
        if(c>='0' && c<='9') {
            book[c-'0']++;
        }
    }
    for(int i=9;i>=0;i--) {
        for(int j=1;j<=book[i];j++) {
            cout<<i;
        }
    }
    return 0;
}