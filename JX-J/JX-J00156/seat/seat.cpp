#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[1005];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int len = n * m;
    for(int i = 1; i <= len; i++) cin >> a[i];
    int num = a[1], pos = 0;
    sort(a + 1, a + len + 1, cmp);
    for(int i = 1; i <= len; i++) if(a[i] == num) pos = i;
    int x, y;
    if(pos % n != 0) x = pos / n + 1;
    else x = pos / n;
    if(x % 2 == 1) y = pos - (n * x - n);
    if(x % 2 == 0) y = n * x - pos + 1;
    cout << x << " " << y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
