#include <bits/stdc++.h>
using namespace std;
int cnt[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<int(s.size());i++)
    {
        if('0'<=s[i]&&s[i]<='9') cnt[int(s[i]-'0')]++;
    }
    string ans="";
    bool flag=false;
    for(int i=9;i>=0;i--)
    {
        if(i>0)
        {
            if(cnt[i]>0) flag=true;
            for(int j=1;j<=cnt[i];j++) cout<<char(i+'0');
        }
        else
        {
            if(flag)
            {
                for(int j=1;j<=cnt[i];j++) cout<<char(i+'0');
            }
            else cout<<"0";
        }
    }
    return 0;
}
//‐O2 ‐std=c++14 ‐static