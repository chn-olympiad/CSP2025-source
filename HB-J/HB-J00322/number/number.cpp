#include <bits/stdc++.h>
using namespace std;
string s1;
int nu[1000005];
int k;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s1;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] <= '9' && s1[i] >= '0')
        {
            nu[k] = s1[i] - '0';
            k++;
        }
    }
    sort(nu, nu + k);
    k--;
    for (int i = k; i >= 0; i--)
    {
        cout << nu[i];
    }
    return 0;
}