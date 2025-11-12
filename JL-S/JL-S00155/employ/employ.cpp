#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
string b;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>b;
    for(int i=1;i<=n-m+1;i++)
    {
        int cnt=1;
        for(int j=n;j>=i;j--)
        {
            cnt*=j;
            cnt%=998244353;
        }
        cnt=cnt%998244353;
        ans+=cnt;
    }
    cout<<ans%998244353;
    return 0;
}
//Ren5Jie4Di4Ling5%
