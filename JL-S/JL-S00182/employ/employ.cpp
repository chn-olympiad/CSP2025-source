#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int m, n, c[N];
string a;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m;
    cin >> a;
    for(int i = 1; i <= n; i ++){
        scanf("%d", c[i]);
    }
    int ans = 3;
    cout << a % 998244353;
    return 0;
}
