#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
const int N=1e5+5;
const int inf=1e18;
int T,n,a[4][N];
int f[N],cnt[4];
pii tmp[N];

bool cmp(pii x,pii y) { return max(x.fst,x.scd)>max(y.fst,y.scd); }
void solve()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[1][i]>>a[2][i]>>a[3][i];

    int ans=0; cnt[1]=cnt[2]=cnt[3]=0;
    for (int i=1;i<=n;i++)
    {
        if (a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]) cnt[1]++,ans+=a[1][i],f[i]=1;
        else if (a[2][i]>=a[3][i]&&a[2][i]>=a[1][i]) cnt[2]++,ans+=a[2][i],f[i]=2;
        else cnt[3]++,ans+=a[3][i],f[i]=3;
    }

    if (max({cnt[1],cnt[2],cnt[3]})<=n/2) { cout<<ans<<"\n"; return ; }
    int op=1;
    if (cnt[2]>cnt[1]&&cnt[2]>cnt[3]) op=2;
    if (cnt[3]>cnt[1]&&cnt[3]>cnt[2]) op=3;
    for (int i=1;i<=n;i++) if (f[i]==1) f[i]=op; else if (f[i]==op) f[i]=1;
    swap(cnt[1],cnt[op]),swap(a[1],a[op]);

    int tp=0,k=cnt[1]-n/2; int op3=0,op2=0;
    for (int i=1;i<=n;i++) if (f[i]==1) tmp[++tp]={-a[1][i]+a[2][i],-a[1][i]+a[3][i]};
    sort(tmp+1,tmp+1+tp,cmp);
    for (int i=1;i<=k;i++)
    {
        ans+=max(tmp[i].fst,tmp[i].scd);
        if (tmp[i].fst<=tmp[i].scd) op3=1;
        if (tmp[i].scd<=tmp[i].fst) op2=1;
    }
    if ((n&1)==0||(cnt[2]+op2)&&(cnt[3]+op3)) { cout<<ans<<"\n"; return ; }
    // cout<<ans<<"\n";

    if (!(cnt[2]+op2)) op=2; else op=3; int mx=-inf,t=ans; ans=-inf;
    for (int i=k+1;i<=tp;i++) mx=max(mx,op==2?tmp[i].fst:tmp[i].scd);
    for (int i=1;i<=k;i++) ans=max(ans,t-max(tmp[i].fst,tmp[i].scd)+max(mx,min(tmp[i].fst,tmp[i].scd)));
    cout<<ans<<"\n"; 
}
signed main()
{
    // freopen("ea.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>T; while (T--) solve(); return 0;
}