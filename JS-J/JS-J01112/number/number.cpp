#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e2;
char s[N];
int g[12],x,len;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> s;
    len = strlen(s);
    for(int i = 0;i < len;i ++) {
        if(s[i] >= '0' && s[i] <= '9') g[s[i] - 48] ++;
    }
    for(int i = 9;i >= 0;i --) for(int j = g[i];j;j --) cout << i;
    return 0;
}