#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,c;
void check(string s,string b)
{
    for(int i=1;i<=s.length();i++)
    {
        if(s[i]!=b[i])
        {
            a+=s[i];
            c+=b[i];
        }
    }
    a+=' ';
}
int check1(string s,string b)
{
    int acpls=0;
    string d,e;
    for(int i=1;i<=s.length();i++)
    {
        if(s[i]!=b[i])
        {
            d+=s[i];
            e+=b[i];
        }
    }
    string temp,temp1,abcd;
    for(int i=1;i<=a.length();i++)
    {
        if(a[i]!=' ')
        {
            temp+=a[i];
            temp1+=c[i];
        }
        else
        {
            if(temp==d && temp1==e)
                acpls++;
            temp=abcd;
            temp1=abcd;
            continue;
        }
    }
    return acpls;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s,b;
        cin>>s>>b;
        check(s,b);
    }
    for(int i=1;i<=m;i++)
    {
        string s1,b1;
        cin>>s1>>b1;
        cout<<check1<<endl;
    }
}