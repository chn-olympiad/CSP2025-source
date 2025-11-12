#include <bits/stdc++.h>
using namespace std;
int g[100005],ans,t;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            t++;
            g[t]=s[i]-48;
        }
    }
    sort(g+1,g+t+1);
    for(int i=t;i>0;i--)
    {
        cout<<g[i];
    }
    return 0;
}
