#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
const ll MOD=998244353;
ll n;
ll a[10000],sum,ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==3)
    {
        ll op=a[1]+a[2]+a[3];
        ll ui=max(a[1],max(a[2],a[3]));
        if(op>ui*2) cout<<"1";
        else cout<<"0";
    }
    else
    {
        ll qw=0;
        for(int i=3;i<=n-1;i++)
        {
            qw/=2;
            sum+=qw;
            if(i==3)
            {
                for(int j=1;j<=n-1;j++)
                {
                    qw+=j;
                }
                sum+=qw;
            }
        }
        cout<<sum+1;
    }
    return 0;
}
