#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t,n;
struct Pp{
    ll a1=0,a2=0,a3=0;
} a[110000];
ll flag[110000];
ll cmpnum;
bool cmp(Pp a,Pp b){
    if(cmpnum==1) return a.a1>b.a1;
    if(cmpnum==2) return a.a2>b.a2;
    if(cmpnum==3) return a.a3>b.a3;
}
ll solve(ll aaa){
    cmpnum=aaa;
    ll cnt=0;
    sort(a+1,a+n+1,cmp);
    for(ll ii=1;ii<=n/2;ii++){
        ll i=ii,j=ii+n/2;
        ll nowc=0;
        ll aa[4],ab[4];
        aa[1]=a[i].a1;
        aa[2]=a[i].a2;
        aa[3]=a[i].a3;

        ab[1]=a[j].a1;
        ab[2]=a[j].a2;
        ab[3]=a[j].a3;
        for(ll k=1;k<=3;k++){
            for(ll l=1;l<=3;l++){
                if(l==k) continue;
                nowc=max(nowc,aa[k]+ab[l]);
            }
        }
        cnt+=nowc;
    }
    return cnt;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a1;
            cin>>a[i].a2;
            cin>>a[i].a3;
        }
        ll ans=max(solve(1),solve(2));
        ans = max(ans,solve(3));
        cout<<ans<<endl;
    }
    return 0;
}
