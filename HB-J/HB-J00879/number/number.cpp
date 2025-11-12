#include <bits/stdc++.h>
using namespace std;
char a;
priority_queue<char> q;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while (cin >> a)
    {
        if ('0' <= a && a <= '9')
        {
            q.push(a);
        }
    }
    while (!q.empty())
    {
        cout << q.top();
        q.pop();
    }
    return 0;
}