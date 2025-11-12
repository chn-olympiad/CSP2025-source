#include <bits/stdc++.h>
using namespace std;
string s;
const int N = 1e6 + 5;
int num[N];
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int pos = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            pos++;
            num[pos] = s[i] - '0';
        }
    }
    sort(num + 1, num + pos + 1,cmp);
    for (int i = 1; i <= pos; i++)
    {
        cout << num[i];
    }
    cout << '\n';
    return 0;
}
