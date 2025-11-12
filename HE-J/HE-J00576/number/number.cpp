#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin >> str;
    int a = str.length();
    int s[10005];
    int c = 0;
    for(int i = 0;i<=a;i++)
    {
        if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9')
        {
            s[c] = str[i] - '0';
            c += 1;
        }

    }
        int cnt[15];
        for(int i = 0;i<c;i++)
        {
            cnt[s[i]]++;
        }
        for(int i = 9;i > -1;i--)
        {
            for(int k = 0;k<cnt[i];k++)
            {
                cout << i;
            }
        }

    return 0;

}

