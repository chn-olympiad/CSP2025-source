#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n;
ll a[200005][3];
ll pos[200005];
ll cnt[3];
vector<ll> b;
void solve()
{
    n=read();
    for(int i=1;i<=n;i++)for(int j=0;j<3;j++)a[i][j]=read();
    for(int i=0;i<3;i++)cnt[i]=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)if(a[i][j]>a[i][pos[i]])pos[i]=j;
        cnt[pos[i]]++;
        res+=a[i][pos[i]];
    }
    // cout<<res<<'\n';
    ll rpos=-1;
    for(int i=0;i<3;i++)if(cnt[i]>n/2)rpos=i;
    if(rpos==-1){cout<<res<<'\n';return;}
    b.clear();
    for(int i=1;i<=n;i++)
    {
        if(pos[i]!=rpos)continue;
        ll maxa=0;
        for(int j=0;j<3;j++)
        {
            if(j==rpos)continue;
            maxa=max(maxa,a[i][j]);
        }
        b.push_back(a[i][pos[i]]-maxa);
    }
    sort(b.begin(),b.end());
    ll c=cnt[rpos]-n/2;
    for(int i=0;i<c;i++)res-=b[i];
    cout<<res<<'\n';
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    // clock_t start=clock();
    ll c=0,t=read();
    while(t--)solve();
    // clock_t end=clock();
    // cerr<<(end-start)*1.00/CLOCKS_PER_SEC<<'\n';
    return 0;
}