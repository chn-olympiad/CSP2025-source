#include<bits/stdc++.h>
using namespace std;
string s;
string num;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int l = s.size();
    int a = 0;
    for(int i = 0; i <= l; i++)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            num[a] = s[i];
            a++;
        }
    }
    for(int i = 0; i <= a; i++)
    {
        for(int j = i; j <= a; j++)
        {
            if(num[j] >= num[i])
            {
                swap(num[i],num[j]);
            }
        }
    }
    for(int i = 0; i <= a; i++)
    {
        cout << num[i];
    }
    return 0;
}
