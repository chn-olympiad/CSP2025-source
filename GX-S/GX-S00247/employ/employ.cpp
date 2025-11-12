#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
char s[510];
bool ch[510];
ll a[510],sum[510];
ll z;
bool dw(ll qwq)
{
    int no=0,yes=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1'&&no<sum[i])yes++;
        else no++;
    }
    return yes>=m;
}
void iv(ll ans)
{
    if(ans>n)
    {
        if(dw(1))z++;
        z%=998244353;
    }
    for(ll i=1;i<=n;i++)
    {
        if(!ch[i])
        {
            sum[ans]=a[i];
            ch[i]=true;
            iv(ans+1);
            ch[i]=false;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>s[i];
    for(ll i=1;i<=n;i++)cin>>a[i];
    iv(1);
    cout<<z;
    return 0;
}
