#include"bits/stdc++.h"
using namespace std;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>s;
    bool vis[1000000];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=1000000;i++)
    {
        if(s[i]>='1' && s[i]<='9')
        {
            a[i]=s[i];
            vis[i]==true;
        }
    }
    for(int i=0;i<1000000;i++)
    {
        if(a[i]<=a[i+1] || a[i]>=a[i-1]);
            swap(a[i],a[i+1]);
    }
    cout<<a;

    return 0;
}
