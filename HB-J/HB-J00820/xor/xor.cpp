#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n,k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==1)
    {
        ll cnt=0;
        for(int i=0;i<n;i++)
        {
            ll x;cin>>x;
            if(x==1) cnt++;
        }
        cout<<cnt;
        return 0;
    }
    if(k==0)
    {
        ll cnt=0;
        if(n==2)
        {
            ll p,q;cin>>p>>q;
            if(p==q&&p!=0&&q!=0||p!=0&&q==0||p==0&&q!=0)
            {
                cout<<1;
            }
            if(p==0&&q==0) cout<<2;
            else cout<<0;
        }
        ll p,q;cin>>p>>q;
        if(p<=1&&q<=1)
        {
            for(int i=0;i<n-2;i++)
            {
                ll x;cin>>x;
                if(x==0) cnt++;
            }
            cout<<cnt;
        }
        else
        {
            ll o=-1;
            for(int i=0;i<n-2;i++)
            {
                ll x;cin>>x;
                if(x==0) cnt++;
                else if(x==o) {cnt++;i++;}
                o=x;
            }
            cout<<cnt;
        }
        return 0;
    }
    cout<<n;
    return 0;
}
