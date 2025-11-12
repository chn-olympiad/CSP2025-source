#include <bits/stdc++.h>
using namespace std;
int num[10]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        if(isdigit(s[i]))
        {
            num[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(num[i]>0)
        {
            cout<<i;
            num[i]--;
        }
    }
    return 0;
}
