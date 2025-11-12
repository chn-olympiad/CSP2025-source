#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    memset(cnt, 0, sizeof(cnt));
    cin >> s;
    for(int i = 1;i <= s.size();i ++)
    {
        if(isdigit(s[i - 1]))
        {
            cnt[int(s[i-1])-'0'] ++;
        }
    }
    for(int i = 9;i >= 0;i --)
    {
        while(cnt[i] != 0)
        {
            cout << i;
            cnt[i] --;
        }
    }
    return 0;
}
//ACACACACAC
//HXYHXYHXY
