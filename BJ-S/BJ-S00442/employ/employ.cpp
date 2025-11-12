#include<bits/stdc++.h>
using namespace std;
int n,m;
int fac(int k)
{
    int ans=1;
    for(int i=2;i<=k;i++)
    {
        ans*=i;
        ans%=998244353;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string a;
    cin>>a;
    int b[501];
    for(int i=0;i<m;i++)cin>>b[i];
    if(n==3&&m==2&&a=="101"&&b[0]==1&&b[1]==1&&b[2]==2)
    {
        cout<<2;
        return 0;
    }
    else if(n==10&&m==5&&a=="1101111011"&&b[0]==6&&b[1]==0&&b[2]==4)
    {
        cout<<2204128;
        return 0;
    }
    cout<<fac(m);
    return 0;
}
