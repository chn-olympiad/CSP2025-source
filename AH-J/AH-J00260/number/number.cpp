#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 0;
string s, p;
LL cnt[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    LL len = s.size();
    for(LL i=0; i<len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            cnt[s[i] - '0'] ++;
        }
    }
    for(LL i=9; i>=0; i--)
    {
        for(LL j=1; j<=cnt[i]; j++)
        {
            p += (i+'0');
        }
    }
    cout << p;
    return 0;
}
