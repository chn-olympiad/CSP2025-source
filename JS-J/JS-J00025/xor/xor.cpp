#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define str string
#define bstr basic_string
struct qjian{
    ll l,r,len;
    bool operator<(const qjian b)const{
        if(!((l<=b.l&&r>=b.r)||(l>=b.l&&r<=b.r)||(l<=b.r&&l>=b.l)||(r>=b.l&&r<=b.r)))return l<b.l;
        return len<b.len;
    }
};
int main(){
    #ifndef DXX_DEBUG
        freopen("xor.in","r",stdin);
        freopen("xor.out","w",stdout);
    #endif
    ll n,k;
    cin>>n>>k;
    vec<ll>nums;
    vec<qjian>ans;
    for(ll i=0;i<n;i++){
        ll num;
        cin>>num;
        nums.push_back(num);
    }
    for(ll i=0;i<n;i++){
        for(ll j=i;j<n;j++){
            //    cout<<i<<' '<<j<<' ';
            ll xorre=nums[i];
            for(ll l=i+1;l<=j;l++){
                xorre=nums[l] xor xorre;
            //    cout<<nums[l]<<' ';
            }
        //    cout<<xorre<<'\n';
            if(xorre==k)ans.push_back({i,j,j-i+1});
        }
    }
    sort(ans.begin(),ans.end());
    ll befl=0,befr=LLONG_MAX,beflen=LLONG_MAX,fans=1;
    for(auto b:ans){
        //    cout<<b.l<<' '<<b.r<<' '<<b.len<<'\n';
        if((befl<=b.l&&befr>=b.r)||(befl>=b.l&&befr<=b.r)||(befl<=b.r&&befl>=b.l)||(befr>=b.l&&befr<=b.r)){
           if(beflen>b.len){
            befl=b.l;
            befr=b.r;
            beflen=b.len;
           }
        }else{
            fans++;
            befl=b.l;
            befr=b.r;
            beflen=b.len;
        }
    }
    cout<<fans<<'\n';
    return 0;
}
