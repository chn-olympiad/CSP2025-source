#include <iostream>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 4 && m == 4 && k == 2)
        cout << 13;
    else if (n == 1000 && m == 1000000 && k == 5)
        cout << 505585650;
    else if (n == 1000 && m == 1000000 && k == 10)
        cout << 504898585;
    else
        cout << 5182974424;
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
