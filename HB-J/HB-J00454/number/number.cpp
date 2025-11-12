#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a;
    cin>>s;
    int d[1000005]={};
    int x=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            d[++x]=int(s[i])-'0';
        }
    }
    sort(d+1,d+x+1,f);
    for(int i=1;i<=x;i++)
    {
        cout<<d[i];
    }
    cout<<"\n";
    return 0;
}
