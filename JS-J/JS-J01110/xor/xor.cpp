#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500001];
string qian[500001], s[500001];
string to_two(long long x)
{
    string ans = "";
    while(x != 0)
    {
        int c = x % 2;
        x /= 2;
        ans = (char)(c + '0') + ans;
    }
    return ans;
}
string add(string x, string y)
{
    string ans = "";
    int u = x.size(), v = y.size();
    if(u < v) for(int i = 1;i <= v - u;i++) x = '0' + x;
    if(v < u) for(int i = 1;i <= u - v;i++) y = '0' + y;
    int si = max(u, v);
    for(int i = 0;i < si;i++) 
    {
        if(x[i] != y[i]) ans = ans + '1';
        else ans = ans + '0';
    }
    return ans;
}
long long to_ten(string s)
{
    long long ans = 0;
    for(int i = s.size() - 1;i >= 0;i--) ans = ans + (long long)(s[i] - '0') * pow(2, (s.size() - i - 1));
    return ans;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    string str = to_two(k);
    cout << str << endl;
    for(int i = 1;i <= n;i++) 
    {
        cin >> a[i];
        if(a[i] == 0) s[i] = "0";
        else s[i] = to_two(a[i]);
        qian[i] = add(qian[i - 1], s[i]);
    }
    int zz = 0, sum = 0;
    for(int i = 1;i <= n;i++) 
    {
        if(a[i] == k) {sum++, zz = i;continue;}
        for(int j = zz + 1;j < i;j++) 
        {
            if(to_ten(add(qian[i], qian[j - 1])) == k) {sum++, zz = i;break;}
        }
    }
    cout << sum << endl;
    return 0;
}