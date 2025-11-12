#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            return 0;
        }
        else
        {
            if(s[i]<s[i+1])
            {
                int t=s[i];
                s[i]=s[i+1];
                s[i+1]=t;
            }
        }
        cout<<s[i];
    }
return 0;
}

