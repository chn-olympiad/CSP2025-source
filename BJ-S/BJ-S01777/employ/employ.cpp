#include<bits/stdc++.h>
#define ll long long
const int maxn=505;
using namespace std;
long long n,m;
string s;
int c[maxn];
long long ans1=1,cnt;
long long mod=998244353;
long long ans(long long n)
{
    for(int i=1;i<=n;i++)
    {
        ans1=(ans1*i)%mod;
    }
    return ans1;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)
        {
            cnt++;
        }
    }
    cout<<ans(n-cnt);
}
