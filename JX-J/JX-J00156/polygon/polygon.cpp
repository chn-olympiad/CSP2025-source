#include <iostream>
#include <algorithm>
using namespace std;

int n, a[5005];
long long sum[5005];
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if(n == 3)
    {
        if(a[1] + a[2] > a[3]) cout << 1;
        else cout << 0;
    }
    else{
        for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    bool f = false;
    for(int i = 3; i <= n; i++)
    {
        int k = a[i] * 2;
        if(sum[i] <= k) continue;
        else f = true;
    }

    if(f == false) cout << 0;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
