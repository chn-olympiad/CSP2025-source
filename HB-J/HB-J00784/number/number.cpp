#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int num[1001000],numlen=-1;
    for (int i=0;i<s.length();i++)
    {
        if ('0'<=s[i]&&s[i]<='9')
            num[++numlen]=s[i]-'0';
    }
    sort(num,num+numlen+1);
    for (int i=numlen;i>=0;i--)
    {
        cout<<num[i];
    }
    return 0;
}
