#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[20]={0};
    bool b=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[s[i]-'0']++;
            if(s[i]>'0'&&!b)
            {
                b=1;
            }
        }
    }
    if(!b)
    {
        cout<<0;
        return 0;
    }
    string ans={};
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<a[i];j++)
        {
            ans+=i+'0';
        }
    }
    cout<<ans;
    return 0;
}
