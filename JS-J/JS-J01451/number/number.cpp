#include <bits/stdc++.h>
using namespace std;
int mark[10] = {0};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        if(s[i] >= '0' && s[i] <= '9')
            mark[ s[i]-'0' ]++;
    for(int i = 9; i >= 0; i--)
    {
        while(mark[i] > 0)
        {
            cout << i;
            mark[i]--;
        }
        if(i==0) return 0;
    }
    return 0;
}
