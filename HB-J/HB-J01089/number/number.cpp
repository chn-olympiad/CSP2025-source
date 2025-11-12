#include <bits/stdc++.h>
using namespace std;

int s[15];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string str;
    cin>>str;

    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            s[str[i]-'0']++;
        }
    }

    for(int i=9;i>=0;i--)
    {
        while(s[i]--)
        {
            cout<<i;
        }
    }

    return 0;
}
