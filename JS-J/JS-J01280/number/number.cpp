#include <iostream>
using namespace std;

string s;
int box[15];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        box[int(s[i] - '0')]++;
    for (int i = 9; i >= 0; i--)
        if (box[i] > 0)
            for (int j = 1; j <= box[i]; j++)
                cout << i;
    return 0;
}
