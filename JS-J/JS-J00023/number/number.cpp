#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[10];
string s;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(ll i = 0;i < s.size();i++) {
        if(s[i] >= '0' && s[i] <= '9')
            a[s[i] - '0']++;
    }
    for(ll i = 9;i >= 0;i--) {
        for(ll j = 1;j <= a[i];j++)
            printf("%lld",i);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
