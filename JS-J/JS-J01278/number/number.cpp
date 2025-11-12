#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long n;
    map<long long,long long>m;
    cin >> s;
    for(long long i = 0;i < s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')m[s[i]-48]++;
    }
    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= m[i];j++)
        {
            cout << i;
        }
    }
    return 0;
}
