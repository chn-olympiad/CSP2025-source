#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
ll t,n,a[N][3],sc[N],cnt[3];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cnt[1]=cnt[2]=cnt[3]=0;
        ll ans=0;
        cin>>n;
        for(ll i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=max(a[i][2],a[i][3])){
                cnt[1]++,sc[i]=1,ans+=a[i][1];
            }else if(a[i][2]>=max(a[i][1],a[i][3])){
                cnt[2]++,sc[i]=2,ans+=a[i][2];
            }else{
                cnt[3]++,sc[i]=3,ans+=a[i][3];
            }
        }
        if(cnt[1]>n/2){
            vector<ll> num;
            for(ll i=1;i<=n;i++){
                if(sc[i]==1){
                    num.push_back(min(a[i][1]-a[i][2],a[i][1]-a[i][3]));
                }
            }
            sort(num.begin(),num.end());
            for(ll i=0;i<cnt[1]-n/2;i++){
                ans-=num[i];
            }
        }else if(cnt[2]>n/2){
            vector<ll> num;
            for(ll i=1;i<=n;i++){
                if(sc[i]==2){
                    num.push_back(min(a[i][2]-a[i][1],a[i][2]-a[i][3]));
                }
            }
            sort(num.begin(),num.end());
            for(ll i=0;i<cnt[2]-n/2;i++){
                ans-=num[i];
            }
        }else if(cnt[3]>n/2){
            vector<ll> num;
            for(ll i=1;i<=n;i++){
                if(sc[i]==3){
                    num.push_back(min(a[i][3]-a[i][1],a[i][3]-a[i][2]));
                }
            }
            sort(num.begin(),num.end());
            for(ll i=0;i<cnt[3]-n/2;i++){
                ans-=num[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
