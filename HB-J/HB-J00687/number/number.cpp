#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    getline(cin,s);
    int q[s.size()]={},i,w=0;
    for(i=0;i<=s.size();i++)
    {
        if(48<=s[i]&&s[i]<=57)
           {
               q[i]=s[i]-48;
               w++;
           }
    }
    sort(q,q+s.size(),cmp);
    if(q[0]==0)
    {
       cout<<0;
       return 0;
    }
    for(i=0;i<w;i++)
    {
        cout<<q[i];
    }
    return 0;
}
