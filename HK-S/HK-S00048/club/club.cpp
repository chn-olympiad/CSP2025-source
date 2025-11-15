#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll n, cnt[3], tests, ans, tmp;
pair<ll, ll> aa[MAXN][3];
vector<ll> v;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>tests;
    while(tests--){
        cnt[0]=cnt[1]=cnt[2]=0;
        cin>>n;
        ans=0;
        for(ll i=1; i<=n; i++){
            cin>>aa[i][0].first>>aa[i][1].first>>aa[i][2].first;
            aa[i][0].second=0;
            aa[i][1].second=1;
            aa[i][2].second=2;
            sort(aa[i],aa[i]+3);
            cnt[aa[i][2].second]++;
            ans+=aa[i][2].first;
        }
        v.clear();
        tmp=-1;
        if(cnt[0]>n/2) tmp=0;
        if(cnt[1]>n/2) tmp=1;
        if(cnt[2]>n/2) tmp=2;
        if(tmp!=-1){
            for(ll i=1; i<=n; i++){
                if(aa[i][2].second==tmp){
                    v.push_back(aa[i][2].first-aa[i][1].first);
                }
            }
            sort(v.begin(), v.end());
            for(ll i=0; i<cnt[tmp]-n/2; i++){
                ans-=v[i];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}