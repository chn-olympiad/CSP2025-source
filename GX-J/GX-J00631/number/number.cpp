#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,d="";
    cin>>s;
    int a[1000000],ai=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            a[ai]=s[i]-'0';
            ai++;
        }
    }
    sort(a,a+ai);
    for(int i=ai-1;i>=0;i--)
    {
        d+=a[i]+'0';
    }
    cout<<d;
    return 0;
}
