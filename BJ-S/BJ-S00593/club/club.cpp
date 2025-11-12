#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,ms,wc,mi,need=0;
struct node
{
    ll a,b,c;
}a[100100];
ll cnt[3][100100],siz[3];
ll ans=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=siz[0]=siz[1]=siz[2]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            ms=-2e9,wc=-1,mi=2e9;
            if(ms<a[i].a) ms=a[i].a,wc=0;
            if(ms<a[i].b) ms=a[i].b,wc=1;
            if(ms<a[i].c) ms=a[i].c,wc=2;
            if(wc!=0) mi=min(mi,ms-a[i].a);
            if(wc!=1) mi=min(mi,ms-a[i].b);
            if(wc!=2) mi=min(mi,ms-a[i].c);
        //    cout<<wc<<":"<<ms<<" "<<mi<<endl;
            ans+=ms,cnt[wc][++siz[wc]]=mi;
        }
    //    cout<<endl;
        for(int i=0;i<3;i++)
        {
            sort(cnt[i]+1,cnt[i]+siz[i]+1);
            /*
            cout<<i<<":";
            for(int j=1;j<=siz[i];j++)
            {
                cout<<cnt[i][j]<<" ";
            }
            cout<<endl;//*/
        }
        if(siz[0]*2>n)
        {
            need=siz[0]-n/2;
            for(int i=1;i<=need;i++) ans-=cnt[0][i];
        }
        if(siz[1]*2>n)
        {
            need=siz[1]-n/2;
            for(int i=1;i<=need;i++) ans-=cnt[1][i];
        }
        if(siz[2]*2>n)
        {
            need=siz[2]-n/2;
            for(int i=1;i<=need;i++) ans-=cnt[2][i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
