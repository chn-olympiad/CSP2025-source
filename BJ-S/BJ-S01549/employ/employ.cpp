#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[1111];
long long cnt=1,ct;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    ct=n;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)ct--;
    }
    if(ct<m)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=ct;i++)
    {
        cnt*=i;
        cnt%=mod;
    }
    cout<<cnt;
    return 0;
}
