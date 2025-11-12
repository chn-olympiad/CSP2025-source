#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,INF=1e9+7;
int T,n;
int a[N][3],to[N],cnt[3];
int st[N],top;
void solve(){
    ll ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int id=0;
        for(int j=0;j<3;j++) {
            cin>>a[i][j];
            if(a[i][j]>a[i][id]) id=j;
        }
        to[i]=id,cnt[id]++;
        ans+=a[i][id];
    }
    int id=0;
    for(int i=0;i<3;i++) {
        if(cnt[i]>cnt[id]) id=i;
    }
    if(cnt[id]<=n/2) {
        cout<<ans<<'\n';
        for(int i=0;i<3;i++) cnt[i]=0;
        return;
    }
    int k=cnt[id]-n/2;
    top=0;
    for(int i=1;i<=n;i++) {
        if(to[i]==id) {
            int x=-INF;
            for(int j=0;j<3;j++) if(j!=id) x=max(x,a[i][j]);
            st[++top]=x-a[i][id];
        }
    }
    sort(st+1,st+top+1,[](int x,int y){return x>y;});
    // for(int i=1;i<=top;i++) cerr<<st[i]<<' ';cerr<<'\n';
    for(int i=1;i<=k;i++) ans+=st[i];
    cout<<ans<<'\n';
    for(int i=0;i<3;i++) cnt[i]=0;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}