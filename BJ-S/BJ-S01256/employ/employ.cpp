#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll b[200];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    string x;
    cin>>x;
    bool f=1;
    for(int i=0;i<x.size();i++)
    {
        if(x[i]=='0')
        {
            f=0;
            break;
        }
    }
    if(f)
    {
        b[1]=1;
        b[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=b[0];j++) b[j]*=i;
            for(int j=1;j<=b[0];j++)
            {
                b[j+1]+=b[j]/10;
                b[j]%=10;
                if(j==b[0] && b[j+1]) b[0]++;
            }
        }
        ll h=199;
        while(!b[h]) h--;
        for(int i=h;i>=1;i--) cout<<b[i];
        cout<<endl;
        return 0;
    }
    if(n==m)
    {
        cout<<0<<endl;
        return 0;
    }
    ll ans=0;
    string y="";
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
        y+=char(i);
    }
    do
    {
        ll cnt=0,pass=0;
        for(int i=0;i<y.size();i++)
        {
            ll d=(ll)y[i];
            if(x[i]=='0' || cnt>=a[d]) cnt++;
            else pass++;
        }
        if(pass>=m) ans++;
    }while(next_permutation(y.begin(),y.end()));
    cout<<ans<<endl;
    return 0;
}
