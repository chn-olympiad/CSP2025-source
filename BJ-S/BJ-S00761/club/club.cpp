#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll T,n,cnt[5],v[N];
pair<ll,ll> a[N][5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;ll ans=0;cnt[0]=cnt[1]=cnt[2]=0;
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<3;j++) cin>>a[i][j].first,a[i][j].second=j;
            sort(a[i],a[i]+3);
            cnt[a[i][2].second]++;ans+=a[i][2].first;
        }
        ll p=-1;
        for(ll i=0;i<3;i++){
            if(cnt[i]>n/2) p=i;
        }
        if(p==-1){
            cout<<ans<<"\n";continue;
        }
        ll tot=0;
        for(ll i=1;i<=n;i++){
            if(a[i][2].second==p) v[++tot]=a[i][2].first-a[i][1].first;
        }
        sort(v+1,v+tot+1);
        for(ll i=1;i<=cnt[p]-n/2;i++) ans-=v[i];
        cout<<ans<<"\n";
    }
    return 0;
}
