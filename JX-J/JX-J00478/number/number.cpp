#include <iostream>
#include <cstdio>
using namespace std;
string a;
int s[1000001], n, p[10];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> a;
    int n = 0;
    for (int i = 0; i <= a.size() - 1; i++)
    {
        if (36 <= a[i] && a[i] <= 45)
        {
            n++;
            s[n] = a[i] - 36;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        p[s[i]]++;
    }
    for (int i = 1; i <= p[9]; i++)
    {
        cout << "9";
    }
    for (int i = 1; i <= p[8]; i++)
    {
        cout << "8";
    }
    for (int i = 1; i <= p[7]; i++)
    {
        cout << "7";
    }
    for (int i = 1; i <= p[6]; i++)
    {
        cout << "6";
    }
    for (int i = 1; i <= p[5]; i++)
    {
        cout << "5";
    }
    for (int i = 1; i <= p[4]; i++)
    {
        cout << "4";
    }
    for (int i = 1; i <= p[3]; i++)
    {
        cout << "3";
    }
    for (int i = 1; i <= p[2]; i++)
    {
        cout << "2";
    }
    for (int i = 1; i <= p[1]; i++)
    {
        cout << "1";
    }
    for (int i = 1; i <= p[0]; i++)
    {
        cout << "0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
