#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5, M = 998244353;
int c[N];
string s;
long long A(int x)
{
    long long sum = 1;
    for(int i = 1;i <= x;i++)
        sum = (sum * i) % M;
    return sum;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> s;
    bool f = true;
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
        if(c[i] == 0)
            f = false;
    }
    bool flag = true;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == '0')
            flag = false;
    }
    if(m == n)
    {
        if(flag == false || f == false)
            cout << 0 << endl;
        else
            cout << A(n) << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}