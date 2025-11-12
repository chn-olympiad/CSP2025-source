//11:38 12pts easy
#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int MAXN = 5e3 + 5;

int n;
int sum, maxx;
int l[MAXN];

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    buff;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i];
        sum += l[i];
        maxx = max(l[i], maxx);
    }

    if (sum > 2 * maxx) //12pts
    {
        cout << 1;
        return 0;
    }
    else
    {
        cout << 0;
        return 0;
    }
    return 0;
}
