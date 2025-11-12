#include <bits/stdc++.h>
using namespace std;
string s;
long long a[10000005], tot;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> s;
    for (long long i = 0; i < s.size(); ++i){
        if (isdigit(s[i]))
            a[++tot] = s[i] - '0';
    }
    sort(a, a + tot + 1);
    for (long long i = tot; i >= 1; --i)
        cout << a[i];
    return 0;
}
