#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll a[N];
ll qzh[N];
int main(){
    //Open IO Files
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ll n,k;
    scanf("%lld%lld",&n,&k);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i==1)qzh[i]=a[i];
        else qzh[i]=qzh[i-1]^a[i];
    }
    vector<pair<ll,ll> >ans;
    for(ll i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((qzh[i-1]^qzh[j])==k){
                ans.push_back(make_pair(i,j));
                break;
            }
        }
    }
    ll Size=ans.size(),lst=0,num=1;
    for(ll i=1;i<ans.size();i++){
        if(ans[lst].second>=ans[i].first){
            if(ans[lst].second>=ans[i].second)lst=i;
            Size--;
        }else lst=i;
    }
    printf("%lld\n",Size);
    //Close IO Files
    fclose(stdin);
    fclose(stdout);
    return 0;
}