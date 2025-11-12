#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N = 1e4+7;

string s;
int t[12];

signed main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            t[s[i]-'0']++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 1; j <= t[i]; j++)
        {
            cout << i;
        }
    }



    return 0;
}
