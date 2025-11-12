#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int a[N + 10], n;
int main()
{
    freopen("number.in", "r", "stdin");
    freopen("number.out", "w", "stdout");
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for(int j = 1; j <= n; j++)
        {
            if(a[j] < a[j + 1]) swap(a[j], a[j + 1]);
        }
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
