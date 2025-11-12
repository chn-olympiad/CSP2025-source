#include<bits/stdc++.h>
using namespace std;
int mys(int a, int b)
{
    int n = 1;
    for (int i = 1; i <= b; i ++)
    {
        n *= a;
    }
    return n;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int k = 0;
    int n[1000010] = {};
    for (int i = 0; i < s.size(); i ++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            n[k] = s[i] - '0';
            k ++;
        }
    }
    for (int i = 1; i < k; i ++)
    {
        for (int j = 1; j < k; j ++)
        {
            if (n[j] > n[j - 1])
            {
                swap(n[j], n[j - 1]);
            }
        }
    }
    for (int i = 0; i < k; i ++)
    {
        cout << n[i];
    }
    return 0;
}
