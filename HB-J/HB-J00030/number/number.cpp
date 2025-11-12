#include <bits/stdc++.h>

using namespace std;

const int N = 20;

string str;
int t[N];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> str;

    int len = str.size();

    for(int i = 0;i < len;++ i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            t[int(str[i] - '0')] += 1;
        }
    }


    for(int i = 9;i >= 0;-- i)
    {
        for(int j = 1;j <= t[i];++ j)
        {
            cout << i;
        }
    }

    return 0;
}
