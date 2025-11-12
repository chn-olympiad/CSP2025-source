#include<bits/stdc++.h>
using namespace std;
long long a[1000006],pos=0;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string x;cin>>x;
    for(long long i=0;i<x.size();i++)
    {
        if(x[i]<='9' && x[i]>='0')a[++pos]=x[i]-'0';
    }
    sort(a+1,a+pos+1,cmp);
    if(a[1]==0)
    {
        cout<<0;
        return 0;
    }
    else
    {
        string x="";
        for(long long i=1;i<=pos;i++)
        {
            x=x+char(a[i]+'0');
        }
        cout<<x;
    }
    return 0;
}
