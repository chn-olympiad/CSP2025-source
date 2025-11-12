#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c[N];
bool cmp (int a,int b) {
    return a > b;
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int k = 0;
    for (int i=0;i<s.size();++i) if (s[i] >= '0' && s[i] <= '9') c[++k] = s[i] - 48;
    sort(c+1,c+1+k,cmp);
    for (int i=1;i<=k;++i) cout << c[i];
    return 0;
}
