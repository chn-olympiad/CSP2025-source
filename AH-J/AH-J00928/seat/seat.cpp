#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[110],r;
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m>>r;
    s[1]=r;
    for(int i=2;i<=n*m;i++) cin>>s[i];
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==r)
        {
            r=i;
            break;
        }
    }
    ll cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
            {
                cnt++;
                if(cnt==r)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--)
            {
                cnt++;
                if(cnt==r)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
