#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int a,int b) {
    return a > b;
}
string s;
int cnt,a[1000005];
signed main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    for(int i=0; i<=s.size()-1; i++)
        if(s[i] >= '0' && s[i] <= '9')
            a[++cnt] = s[i] - '0';
    sort(a+1,a+cnt+1,cmp);
    for(int i=1; i<=cnt; i++) cout << a[i];
    return 0;
}
