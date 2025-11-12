#include<bits/stdc++.h>;
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long m,i,ans=1;
    cin>>m;
    for(i=2;i<=m;i++)
    {
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
}
