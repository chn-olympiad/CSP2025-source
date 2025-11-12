#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
string two(int n)
{
    string s = "";
    while(n != 0)
    {
        s = char((n % 2) + '0') + s;
        n /= 2;
    }
    return s;
}
int owt(string s)
{
    int n = 0;
    for(int i = 0; i < s.size(); i++)
    {
        n *= 2;
        n += int(s[i] - '0');
    }
    return n;
}
string xora(string a, string b)
{
    string ans = "";
    if(a.size() < b.size()) swap(a, b);
    while(a.size() > b.size()) b = '0' + b;
    for(int i = 0; i < a.size(); i++)
    {
         if(a[i] == b[i])
            ans += '0';
        else ans += '1';
    }
    while(ans[0] == '0') ans.erase(0, 1);
    return ans;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    long long cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt = 0;
        d[i - 1] = a[i - 1];
        for(int j = i; j <= n; j++)
        {
            d[j] = owt(xora(two(a[j]),two(d[j - 1])));
            if(d[j] == k){
                cnt++;
                memset(d, 0, sizeof(d));
            }
        }
        ans = max(cnt, ans);
    }
    cout << ans;
    return 0;
}
