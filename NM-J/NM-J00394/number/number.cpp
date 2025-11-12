#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], n, flag;
string s;

bool cmp (int x, int y){
    return x > y;
}

int main (){
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] == '1') a[i] = 1, flag++;
        if (s[i] == '2') a[i] = 2, flag++;
        if (s[i] == '3') a[i] = 3, flag++;
        if (s[i] == '4') a[i] = 4, flag++;
        if (s[i] == '5') a[i] = 5, flag++;
        if (s[i] == '6') a[i] = 6, flag++;
        if (s[i] == '7') a[i] = 7, flag++;
        if (s[i] == '8') a[i] = 8, flag++;
        if (s[i] == '9') a[i] = 9, flag++;
        if (s[i] == '0') a[i] = 0, flag++;
    }
    sort (a, a + n,cmp);
    for (int i = 0; i < flag; i++){
        cout << a[i];
    }
    return 0;
}
