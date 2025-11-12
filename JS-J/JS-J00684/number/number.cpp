#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{

    return a>b;
}
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a+1,a+cnt,cmp);
    bool fl=0;
    for(int i=1;i<cnt;i++)
    {
        if(!fl)
        {
            if(a[i])fl=1;
        }
        if(fl)cout<<a[i];
    }
    if(!fl)cout<<0;
    return 0;
}
