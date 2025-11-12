#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500+10;
ll n,m;
bool s[N];
ll c[N],p[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        s[i]=(ch=='1');
    }
    for(ll i=1;i<=n;i++)
        cin>>c[i];
    for(ll i=1;i<=n;i++)
        p[i]=i;
    ll ans=0;
    do
    {
        ll discnt=0;
        for(ll i=1;i<=n;i++)
        {
            if(discnt>=c[p[i]] || s[i]==0)
            {
                discnt++;
            }
        }
        if(n-discnt>=m)
        {
            ans++;
        }
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<endl;
    return 0;
}