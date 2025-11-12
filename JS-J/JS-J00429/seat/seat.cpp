#include <bits/stdc++.h>

using namespace std;

int n, m, r, a[110], b[20][20];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0;i < n * m;i++){
        cin >> a[i];
    }
    r = a[0];
    sort(a, a + n * m, cmp);
    int t = 0;
    while(a[t] != r){
        t++;
    }
    int x, y;
    x = (t / (n * 2)) * 2;
    t %= (n * 2);
    if(t < n){
        y = t + 1;
    }else{
        x++;
        y = 2 * n - t;
    }
    cout << x + 1 << ' ' << y << endl;

    return 0;
}