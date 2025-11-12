#include<bits/stdc++.h>
using namespace std;
bool px(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,x;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            x+=s[i];
        }
    }
    long long r[x.size()];
    for(int i=0;i<x.size();i++)
    {
        int h=0;
        for(int j=0;j<x.size();j++)
        {
            if(x[i]=='0')h=0;
            if(x[i]=='1')h=1;
            if(x[i]=='2')h=2;
            if(x[i]=='3')h=3;
            if(x[i]=='4')h=4;
            if(x[i]=='5')h=5;
            if(x[i]=='6')h=6;
            if(x[i]=='7')h=7;
            if(x[i]=='8')h=8;
            if(x[i]=='9')h=9;
            r[i]=h;
        }
    }
    sort(r,r+x.size(),px);
    if(r[0]==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<x.size();i++)
    {
        cout<<r[i];
    }
    return 0;
}
