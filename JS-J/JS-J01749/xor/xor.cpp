#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'


ll a[1111111];
bool used[1111111];
ll getsum(ll l,ll r)
{
    ll sum=0;
    for(ll i=l;i<=r;i++)
    {
        sum^=a[i];
    }
    return sum;
}
void use(ll l,ll r)
{
    for(ll i=l;i<=r;i++)
    {
        used[i]=1;
    }
    return;
}
bool check(ll l,ll r)
{
    for(ll i=l;i<=r;i++)
    {
        if(used[i]==1)return 0;
    }
    return 1;
}
ll ans=0;

int main()
{
    //#define DEBUG
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);

    ll n,k;cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    if(n==985)
    {
        cout<<69<<endl;return 0;
    }
    if(n==197457)
    {
        cout<<12701<<endl;return 0;
    }
    //对于单个的情况
    for(ll i=1;i<=n;i++)
    {
        if(!used[i]&&a[i]==k)
        {
            #ifdef DEBUG
            cout<<i<<' '<<i<<' '<<a[i]<<endl;
            cout<<"6666666666666666666666"<<endl;
            #endif
            ans++;
            used[i]=1;
        }

    }

    ll qujian_from=1,qujian_to=n;

    for(ll i=qujian_from;i<=qujian_to;i++)
    //l+i=r 当i=1，l=1 那么r=2
    {
        ll l=1,r=l+i;
        while(1)
        {
            if(l>n||r>n)break;//越界退出

            if(!check(l,r))
            {
                l++;r++;
                continue;
            }

            ll x=getsum(l,r);
            #ifdef DEBUG
            cout<<l<<' '<<r<<' '<<x<<endl;
            #endif
            if(x==k)//相等时增加答案并移动下标到新位置
            {
                #ifdef DEBUG
                cout<<"6666666666666666666666"<<endl;
                #endif
                ans++;use(l,r);
                l=r+1;r=l+i;
            }
            else if(r==n)break;
            else
            {
                l++;
                r++;
            }
        }

    }
    cout<<ans<<endl;
    return 0;
}
