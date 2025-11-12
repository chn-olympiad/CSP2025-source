#include <bits/stdc++.h>
using namespace std;
int cmp(int a, int b)
{
    return a > b;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    vector <int> g;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s.at(i) >= '0' && s.at(i) <= '9')
        {
            g.push_back((int)(s.at(i) - '0'));
        }
    }
    sort(g.begin(), g.end(), cmp);
    for (int i = 0; i < g.size(); ++i) cout << g[i];
    return 0;
}
