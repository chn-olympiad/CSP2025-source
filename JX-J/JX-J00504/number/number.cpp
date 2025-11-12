#include <bits/stdc++.h>
using namespace std;
int cnt[10];
#define endl '\n'
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int maxn = 0, len = s.size(), c, sum = 0;
    for(int i = 0; i< len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            c = s[i]- '0';
            cnt[c]++;
            maxn = max(maxn, c);
        }
    }
    string ans = "";
    if(maxn == 0)
        cout << 0;
    else
    {
        for(int i = 9; i>= 0; i--)
        {
            if(cnt[i])
            {
                while(cnt[i]--)
                {
                    ans+=(i +'0');
                }
            }

        }
        cout << ans;
    }
    return 0;
}
