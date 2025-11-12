#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005],b[5005],sum[5005],x,s;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=n;i>0;i--)
    {
        for(ll j=i-1;j>0;j--)
        {
            x=a[j];
            for(ll k=j-1;k>0;k--)
            {

                x+=a[k];
                //cout<<x<<endl;
                if(x>a[i])
                {
                    s++;
                    s=s%998244353;
                    for(ll z=k-1;z>0;z--)
                    {
                        //cout<<z<<" ";
                        ll u=1,v=1;
                        for(ll g=1;g<=z;g++)
                        {
                            u=u*g;
                            v=v*(k-g);
                        }
                        //cout<<u<<" "<<v<<endl;
                        s+=v/u%998244353;
                    }
                    //cout<<s<<endl;
                    //break;
                    x-=a[k];
                }
            }
        }
    }
    s=s%998244353;
    cout<<s;
    return 0;
}
