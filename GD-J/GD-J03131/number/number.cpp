#include <bits/stdc++.h>
#define int long long
#define gc getchar()
using namespace std;

int read()
{
    int x = 0, f = 1;
    char c = gc;
    for(; !isdigit(c); c = gc) if(c == '-') f = -1;
    for(; isdigit(c); c = gc) x = x * 10 + (c ^ 48);
    return x * f;
}

int a[10];
string s;

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(char c : s) if(isdigit(c)) a[c ^ 48] ++;
    for(int i = 9; i >= 0; i--) while(a[i]) cout << i, a[i]--;
    return 0;
}
