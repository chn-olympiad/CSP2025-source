#include<bits/stdc++.h>
using namespace std;
int c[1000];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m, count1 = 0;
    string s;
    int l = s.size();
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 0; i < l; i++)
    {
        if(s[i] == '1') count1++;
    }
    if(count1 == l)
    {
        long long p = 1;
        for(int i = 1; i <= n; i++)
        {
            p *= i;
            p %= 998244353;
        }
        cout << p;
        return 0;
    }
    return 0;
}
