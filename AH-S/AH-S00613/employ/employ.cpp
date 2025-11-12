#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 505
using namespace std;
int n, m, cnt, now, ok, id;
string s;
int a[MAXN], c[MAXN];
bool check(int x) {
    if(x>n) {
        return ok>=m;
    }
    if(ok>=m) {
        return true;
    }
    if(now>=c[id]||s[x]=='0') {
        now ++;
        id ++;
        return check(x+1);
    }
    ok ++;
    id ++;
    return check(x+1);
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    s = " "+s;
    for(int i=1; i<=n; i++) {
        cin >> c[i];
        a[i] = i;
    }
    do{
        now = 0, ok = 0, id = 1;
        if(check(1)) {
            cnt ++;
        }
    }while(next_permutation(a+1, a+1+n));
    cout << cnt;
    return 0;
}
