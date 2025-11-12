#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll maxn=2e5+5,inf=1e18;
ll n,oid;
struct item{
    ll num[3],mx,id;
}arr[maxn];
vector<item> vec[3];
bool cmp1(item a,item b){
    return a.mx>b.mx;
}
bool cmp2(item a,item b){
    ll mxa=-inf,mxb=-inf;
    for(int i=0;i<3;i++){
        if(i==oid)continue;
        mxa=max(a.num[i],mxa);
        mxb=max(b.num[i],mxb);
    }
    return mxa-a.num[oid]>mxb-b.num[oid];
}
void solve(){
    for(int i=0;i<3;i++){
        vec[i].clear();
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        ll mx=-inf,id=0;
        for(int j=0;j<3;j++){
            cin>>arr[i].num[j];
            if(arr[i].num[j]>mx){
                mx=arr[i].num[j];
                id=j;
            }
        }
        arr[i].mx=mx;
        arr[i].id=id;
    }
    sort(arr+1,arr+n+1,cmp1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        vec[arr[i].id].push_back(arr[i]);
        ans+=arr[i].mx;
    }
    for(int i=0;i<3;i++){
        if(vec[i].size()>n/2){
            oid=i;
            sort(vec[i].begin(),vec[i].end(),cmp2);
            ll out=vec[i].size()-n/2;
            for(int j=0;j<out;j++){
                ll mxa=-inf;
                for(int k=0;k<3;k++){
                    if(k==oid)continue;
                    mxa=max(vec[i][j].num[k],mxa);
                }
                ans+=mxa-vec[i][j].num[oid];   
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll Testcases;
    cin>>Testcases;
    while(Testcases--){
        solve();
    }
    return 0;
}