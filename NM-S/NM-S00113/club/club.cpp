#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,w1,w2,w3,a1,a2,a3;
int d1[N],d2[N],d3[N];
ll ans;
void init(){
    ans=a1=a2=a3=0;
    memset(d1,0,sizeof d1);
    memset(d2,0,sizeof d2);
    memset(d3,0,sizeof d3);
}
void solve(){
    init();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w1>>w2>>w3;
        int mxw=max({w1,w2,w3});
        ans+=mxw;
        if(mxw==w1){
            d1[a1++] = w1-max(w2,w3);
        }else if(mxw==w2){
            d2[a2++] = w2-max(w1,w3);
        }else{
            d3[a3++] = w3-max(w1,w2);
        }
    }
    int mhc=max({a1,a2,a3});
    if(mhc*2<=n){
        cout<<ans<<"\n";
        return;
    }
    if(mhc==a1){
        sort(d1,d1+a1);
        for(int i=0;i<mhc-n/2;i++) ans-=d1[i];
    }else if(mhc==a2){
        sort(d2,d2+a2);
        for(int i=0;i<mhc-n/2;i++) ans-=d2[i];
    }else{
        sort(d3,d3+a3);
        for(int i=0;i<mhc-n/2;i++) ans-=d3[i];
    }
    cout<<ans<<"\n";
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio();cin.tie(0);
    int _;cin>>_;
    while(_--) solve();
	return 0;
}
