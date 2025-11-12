#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[N][3],d0[N],d1[N],d2[N];
void solve(){
    int ans,tot0,tot1,tot2,cnt0,cnt1,cnt2;
    ans=tot0=tot1=tot2=cnt0=cnt1=cnt2=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int s=a[i][0]+a[i][1]+a[i][2];
        int mx=max({a[i][0],a[i][1],a[i][2]});
        int mn=min({a[i][0],a[i][1],a[i][2]});
        int mid=s-mx-mn;
        if(mx==a[i][0]) cnt0++,d0[++tot0]=mx-mid;
        else if(mx==a[i][1]) cnt1++,d1[++tot1]=mx-mid;
        else cnt2++,d2[++tot2]=mx-mid;
        ans+=mx;

    }
    int mxc=max({cnt0,cnt1,cnt2});
    if(mxc<=n/2){
        cout<<ans<<'\n';
        return;
    }
    int t=mxc-n/2;
    if(mxc==cnt0){
        sort(d0+1,d0+tot0+1);
        for(int i=1;i<=t;i++) ans-=d0[i];
    }else if(mxc==cnt1){
        sort(d1+1,d1+tot1+1);
        for(int i=1;i<=t;i++) ans-=d1[i];
    }else{
         sort(d2+1,d2+tot2+1);
        for(int i=1;i<=t;i++) ans-=d2[i];
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
