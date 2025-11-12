#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int sum;
int main()
{
    freopen("number.in","r",number.in);
    freopen("number.out","w",number.out);
    cin >> s;
    int n = sizeof(s);
    int j = 1;
    for (int i = 0;i < n;i++)
    {
        if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' )
        {
            a[j] = s[i];
            sum += 1;
            j++;
        }
    }
    sort(a[1], a[sum]);
    for (int i = sum ;i >= 1;i--)
    {
        cout << a[i];
    }
    return 0;
}
