#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if(s.size()==1)
    {
        cout<<s;
        return 0;
    }
    int k=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {

        }
        else
        {
            s[i]=' ';
        }
    }
    int len=s.size();
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(s[j]>s[i])
            {
                int t=s[j];
                s[j]=s[i];
                s[i]=t;
            }
        }
    }
    for(int i=len; i>=0; i--)
    {
        if(s[i]!=' ')
        {
            cout<<s[i];
        }
    }
    return 0;
}
