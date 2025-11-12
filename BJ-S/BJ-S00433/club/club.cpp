#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
using namespace std;
const int N=1e5+5;
int n,a[N][4],mx[N],cmx[N],cnt[4],b[N];
pii t[4];
inline void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            t[j]=mkp(a[i][j],j);
        }
        sort(t+1,t+4);
        mx[i]=t[3].se,cmx[i]=t[2].se;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=a[i][mx[i]];
        cnt[mx[i]]++;
    }

    // for(int i=1;i<=n;i++)cerr<<mx[i]<<' '<<cmx[i]<<endl;

    int lim=max(max(cnt[1],cnt[2]),cnt[3]);

    // for(int i=1;i<=3;i++)cerr<<cnt[i]<<' ';
    // cerr<<endl;

    if(lim<=n/2){cout<<ans<<'\n';return;}

    // cerr<<ans<<endl;

    int p=1;
    for(int i=1;i<=3;i++)
        if(cnt[i]>cnt[p])p=i;

    // cerr<<p<<endl;

    int tol=0;
    for(int i=1;i<=n;i++)
        if(mx[i]==p)b[++tol]=a[i][mx[i]]-a[i][cmx[i]];
    sort(b+1,b+tol+1);
    int dta=cnt[p]-n/2;

    // cerr<<"Zyx "<<dta<<endl;

    for(int i=1;i<=dta;i++)ans-=b[i];
    cout<<ans<<'\n';
    return;
}
inline void clr(){
    for(int i=1;i<=n;i++)mx[i]=cmx[i]=0,b[i]=0;
    for(int i=1;i<=3;i++)cnt[i]=0;
    return;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;cin>>T;while(T--)solve(),clr();
    return 0;
}