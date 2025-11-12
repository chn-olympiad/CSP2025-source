#include <bits/stdc++.h>
using namespace std;
const int MAXN=507;
const int mod=998244353;
int n,m,c[MAXN];
string s;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<m;i++)
    {
        cin>>c[i];
    }
    bool is_a=true;
    int countOne=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1')
            is_a=false;
        else
            countOne++;
    }
    if(is_a)
    {
        long long ans=0;
        for(int j=m;j<n;j++)
        {
            long long t=1;
            for(int i=n;i>n-j;i--)
            {
                t*=i;
                t%=mod;
            }
            ans+=(t)%mod;
            ans%=mod;
        }
        cout<<ans;
    }
    else if(countOne<m)
        cout<<0;
    return 0;
}