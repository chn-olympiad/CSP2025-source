#include<iostream>
#include<string>
using namespace std;

freopen("number.in", 'r', stdin);
freopen("number.out", 'w', stdout);

int main()
{
    string s;
    int a[10] = {0};
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            a[(int)(s[i] - '0')]++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        while (a[i])
        {
            cout << i;
        }
    }
    return 0;
}