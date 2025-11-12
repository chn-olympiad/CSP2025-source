#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    long long a=0,sum=0,b=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1'||s[i]=='2'||s[i]=='3'||
           s[i]=='4'||s[i]=='5'||s[i]=='6'||
           s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
        {
            a+=1;
        }
    }
    if(a==s.size())
    {
        if(s.size()==1)
        {
            cout<<s;
            return 0;
        }
        else
        {
            for(int j=0;j<s.size();j++)
            {
                int x=10;
                for(int i=0;i<s.size();i++)
                {
                    if(s[i]<x)
                    {
                        x=s[i];
                    }
                }
                for(int k=0;k<s.size();k++)
                {
                    if(s[k]==x)
                    {
                        s[k]='a';
                    }
                }
                sum+=x*b;
                b*=10;
            }
        }

    }
    cout<<sum;
    return 0;
}
