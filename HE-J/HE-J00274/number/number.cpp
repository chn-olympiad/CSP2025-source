#include <bits/stdc++.h>
using namespace std;
string s;
int a[10000005] = {0};
int j = 0;
bool cmp (int a, int b)
{
    return a > b;
}
int main()
{
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            //cout << s[i] << " ";
            a[j] = s[i] - '0';
            //cout << a[j] << " ";
            j++;
        }
    }
    sort (a, a + j, cmp);
    for (int i = 0; i < j; i++)
    {
        cout << a[i];
    }
    cout << '\n';
    return 0;
    //ZAI WO MEN MIAN QIAN, MAI NONG JI MOU YI SHI WU YONG
}
