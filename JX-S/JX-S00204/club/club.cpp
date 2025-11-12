#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;

ll T,n,a[3],b[3],ans;
vector<ll> v[3];
bool cmp(ll x,ll y){return a[x]>a[y];}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n; ans=0;
        for(int i=0; i<3; i++) v[i].clear();
        for(int i=1; i<=n; i++){
            for(int j=0; j<3; j++) scanf("%lld",&a[j]), b[j]=j;
            sort(b,b+3,cmp);
            ans+=a[b[0]];
            v[b[0]].push_back(a[b[0]]-a[b[1]]);
        }
        for(int i=0; i<3; i++){
            ll k=(ll)v[i].size()-n/2;
            if(k>0){
                sort(v[i].begin(),v[i].end());
                for(int j=0; j<k; j++) ans-=v[i][j];
            }
        }
        printf("%lld\n",ans);
    }

    return 0;
}
