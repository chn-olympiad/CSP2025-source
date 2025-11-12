#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1;
    cin>>s;
    long long len=s.size();
    for(int i=0;i<len;i++)
    {
        if('0'<=s[i]&&s[i]<='9') s1+=s[i];
    }
    sort(s1.begin(),s1.end(),cmp);
    cout<<s1;
    return 0;
}
