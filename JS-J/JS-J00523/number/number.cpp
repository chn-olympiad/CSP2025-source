#include <bits/stdc++.h>
using namespace std;
string s;
int box[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if('0' <= s[i] <= '9')
        {
            box[s[i] - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        while(box[i])
        {
            printf("%d",i);
            box[i]--;
        }
    }
    return 0;
}
