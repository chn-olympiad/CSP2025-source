#include <bits/stdc++.h>
#define int long long
using namespace std;
int num[12];
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin >> s;
    bool flag = 1;
    for (int i = 0; i < s.size(); i ++)
    {
        if('0'<=s[i] && s[i] <= '9')
        {
            num[(int)(s[i] - '0')] ++;
            if(s[i]!='0') flag = 0;
        }
    }
    if(flag) printf("0");
    else
    {
        for (int i = 9; i >= 0; i --)
        {
            while(num[i])
            {
                printf("%d",i);
                num[i] --;
            }
        }
    }
    return 0;
}
