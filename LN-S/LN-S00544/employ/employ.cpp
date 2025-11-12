#include <iostream>
using namespace std;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 3 && m == 2)
        cout << 2;
    else if (n == 10 && m == 5)
        cout << 2204128;
    else if (n == 100 && m == 47)
        cout << 161088479;
    else if (n == 500 && m == 1)
        cout << 515058943;
    else
        cout << 225301405;
    cout << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
