#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s.erase(i, 1);
            i--;
        }
    sort(s.begin(), s.end(), greater<char> ());
    if (s[0] == '0')
        cout << 0;
    else
        cout << s;
    return 0;
}
