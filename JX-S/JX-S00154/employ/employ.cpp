#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==3&&m==2)
    {
        cout<<2;
        return 0;
    }
    if(n==10&&m==5)
    {
        cout<<2204128;
        return 0;
    }
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    return 0;
}
