#include <bits/stdc++.h>
using namespace std;
long long A(long long x)
{
    if(x==1){
        return 1;
    }
    else
    {
        //cout<<x<<"*"<<A(x-1)<<endl;
        return (x%998244353)*A(x-1);
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    bool fl=true;
    int a[n],b[n],i;
    for(i=0;i<n;i++)
    {
        b[i]=s[i]-'0';
        if(s[i]=='0')fl=false;
    }
    for(i=0;i<n;i++)cin>>a[i];
    if(m==n&&!(fl))cout<<0;
    else if(m==n&&fl)cout<<A(n)%998244353;
    else if(m!=n&&fl)cout<<(A(n)%998244353)/(A(n-m)%998244353);
    return 0;
}
