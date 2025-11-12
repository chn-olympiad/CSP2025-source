#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

int arr[MAXN];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int len = str.length();
    int sel = 0;

    for (int i = 0; i < len; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            arr[++sel] = str[i] - '0';
        }
    }

    sort(arr + 1, arr + sel + 1);

    for (int i = sel; i >= 1; --i)
    {
        cout << arr[i];
    }

    return 0;
}