#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[11];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for (int i=0;i<=9;i++)
    {
        cnt[i]=0;
    }
    bool f=false;
    for (int i=0;i<(int)s.size();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            cnt[s[i]-'0']++;
            if (s[i]!='0')
            {
                f=true;
            }
        }
    }
    if (f)
    {
        for (int i=9;i>=0;i--)
        {
            while (cnt[i]>0)
            {
                cnt[i]--;
                cout<<i;
            }
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
