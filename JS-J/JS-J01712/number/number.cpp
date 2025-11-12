#include <bits/stdc++.h>
using namespace std;
priority_queue <char> q;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (int i=0;i<s.size();i++)
    {
        if (isdigit(s[i])) q.push(s[i]);
    }
    while (!q.empty()) cout << q.top(),q.pop();
    return 0;
}
