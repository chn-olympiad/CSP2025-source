#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long i=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(s[i]>s[i+1])
            {
                char x;
                x=s[i];
                s[i]=s[i+1];
                s[i+1]=x;
            }
        }
    }
    cout<<s;
    return 0;
}
