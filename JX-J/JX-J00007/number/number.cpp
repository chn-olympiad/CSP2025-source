#include <bits/stdc++.h>
using namespace std;
string s;
int i, j, n=1, a[1000005];
bool b;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(i=0; i<s.size(); i++) {
        if('0'<=s[i]&&s[i]<='9') {
            a[n]=s[i]-'0';
            n++;
        }
    }
    n--;
    for(i=1; i<n; i++) {
            b=true;
        for(j=n; j>i; j--) {
            if(a[j]>a[j-1]) {
                b=false;
                swap(a[j], a[j-1]);
            }
        }
        if(b) break;
    }
    for(i=1; i<=n; i++) {
        printf("%d", a[i]);
    }
    return 0;
}
