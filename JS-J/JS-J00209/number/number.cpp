#include<bits/stdc++.h>
using namespace std;
string s,t;
bool cmp(char a,char b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            t+=s[i];
        }
    }
    sort(t.begin(),t.end(),cmp);
    cout<<t;
    return 0;
}
