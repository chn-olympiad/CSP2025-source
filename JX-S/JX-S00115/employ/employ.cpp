
#include <iostream>
#include <string>
using namespace std;

long long read()
{
    char ch;
    int num = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') num = num * 10 + (ch - '0'), ch = getchar();
    return num;
}
const int mod = 998244353;
int n, m, c[505], pos;
string s;
bool f = false;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    pos = n;
    cin >> s;
    for(int i = 1;i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 0; i <= n - 1; i++)
    {
        if(s[i] == '0') f = true;
    }
    if(f == false)
    {
        long long ans = 1;
        for(int i = 1; i <= n; i++)
        {

            ans *= i;
            ans %= mod;
        }
        cout << ans;
    }
    return 0;
}
