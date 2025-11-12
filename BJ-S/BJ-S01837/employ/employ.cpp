#include<bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, m;
string s;
int c[510];
int T[510];
long long int calc(int x)
{
    long long int ans = 1;
    for(int i = 1; i <= x; i ++) ans = ans * i % P;
    return ans;
}
int a[510];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i ++ ) cin >> c[i];
    if(m == 1)
    {
        cout << 0 << endl;
    }
    else if(m == n)
    {
        bool state = 0;
        for(int i = 1; i <= n; i ++) 
            if(s[i - 1] == '0') 
                state = true;
        for(int i = 1; i <= n; i ++)
            if(c[i] == 0)
                state = true;
        if(state) cout << 0 << endl;
        else cout << calc(n) << endl;
    }
    else if(n <= 18)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i ++) a[i] = i;
        do
        {
            int inpass = 0, pass = 0;
            for(int i = 1; i <= n; i ++ )
            {
                if(s[i - 1] == '0') inpass += 1;
                else if(inpass >= c[a[i]]) inpass += 1;
                else pass += 1;
            }
            if(pass  >= m) cnt += 1;
        } while (next_permutation(a + 1, a + 1 + n));
        cout << cnt << endl;
    }
    else
    {
        long long int ans = 1;
        for(int i = m ;i <= n; i ++) ans = ans * i % P;
        cout << ans << endl;
    }
    return 0;
}