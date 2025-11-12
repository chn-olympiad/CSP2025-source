#include <iostream>
#include <algorithm>
using namespace std;
string s;
int a[1000010], k = 0;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            k++;
            a[k] = int(s[i] - '0');
        }
    }
    sort(a + 1, a + k + 1);
    if(a[k] == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        for(int i = k; i >= 1; i--)
        {
            cout << a[i];
        }
    }
    return 0;
}
