#include <bits/stdc++.h>
using namespace std;
string s;
long long m[10000000],n=0,b;
bool v(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            m[n]=int(s[i])-48;
            n++;
        }
    }
    sort(m,m+n,v);
    if(m[0]==0)
    {
        cout<<0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<m[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
