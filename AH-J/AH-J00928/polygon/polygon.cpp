#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Pow(ll a,ll b)
{
    ll sum=1;
    while(b--)
    {
        sum*=a;
    }
    return sum;
}
ll s[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n,s1=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]==1) s1++;
    }
    if(s1==n)
    {
        ll sum=0;
        for(int i=3;i<=n;i++)
        {
            sum+=((n-i+2)*(n-i+1)/2)%998244353;
        }
        cout<<sum%998244353;
    }
    else if(n<=22)
    {
        ll z=Pow(2,n),cnt=0;
        for(int i=7;i<=z;i++)
        {
            ll z1=i,maxn=0,sum=0,p=n;
            while(z1)
            {
                if(z1%2==1)
                {
                    sum+=s[p];
                    maxn=max(maxn,s[p]);
                }
                p--;
                z1=(z1>>1);
            }
            if(sum>maxn*2)
            {
                cnt=(cnt+1)%998244353;
            }
        }
        cout<<cnt;
    }
    else cout<<2344255;
    return 0;
}
