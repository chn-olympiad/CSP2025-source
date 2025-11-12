#include <bits/stdc++.h>
using namespace std;

string in;
int out[1000005];
bool comp(int x, int y)
{
    return x > y;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> in;
    int cnt = 0;
    for(int i = 0; i < in.length(); i++)
    {
        if('0' <= in[i] && in[i] <= '9')
        {
            out[cnt++] = in[i] - '0';
        }
    }
    sort(out, out + cnt, comp);
    for(int i = 0; i < cnt; i++)
    {
        cout << out[i];
    }
    return 0;
}
