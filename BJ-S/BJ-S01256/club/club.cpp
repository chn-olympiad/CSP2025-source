#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N],c[N];
ll ans,n;
inline ll read()
{
    ll ans=0,f=1;
    char x=getchar();
    while(x<'0' || x>'9')
    {
        if(x=='-') f=-1;
        x=getchar();
    }
    while(x>='0' && x<='9')
    {
        ans=(ans<<1)+(ans<<3)+x-'0';
        x=getchar();
    }
    return ans*f;
}
void solve(ll x,ll A,ll B,ll C,ll z)
{
    if(x>n)
    {
        ans=max(ans,z);
        return ;
    }
    if(A<n/2) solve(x+1,A+1,B,C,z+a[x]);
    if(B<n/2) solve(x+1,A,B+1,C,z+b[x]);
    if(C<n/2) solve(x+1,A,B,C+1,z+c[x]);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    t=read();
    while(t--)
    {
        n=read();
        bool f=1;
        for(int i=1;i<=n;i++)
        {
            a[i]=read();
            b[i]=read();
            c[i]=read();
            if(b[i] || c[i]) f=0;
        }
        if(f)
        {
            sort(a+1,a+1+n,greater<int>());
            ll cnt=0;
            for(int i=1;i<=n/2;i++) cnt+=a[i];
            cout<<cnt<<endl;
            continue;
        }
        ans=0;
        solve(1,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
