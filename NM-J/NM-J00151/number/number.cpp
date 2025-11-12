#include<bits/stdc++.h>
using namespace std;
string str;
int num[1000010];
int needle = 1;
int countnum[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> str;
    for(int i = 0;i < str.size();i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            num[needle] = str[i] - '0';
            needle++;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        countnum[i] = 0;
    }
    for(int i = 1;i <= needle;i++)
    {
        countnum[num[i]]++;
    }
    for(int i = 9;i >= 0;i--)
    {
        cout << countnum[i] * (i + '0');
    }
    return 0;
}
