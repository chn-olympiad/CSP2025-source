#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 5e10+10;
ll n,a[500010][4];

ll dfs(ll c,ll s,ll bm1,ll bm2,ll bm3){
    if(c > n) return s;
    ll gx1=0,gx2=0,gx3=0,k=n/2;
    if(bm1<k) gx1 = dfs(c+1,s+a[c][1],bm1+1,bm2,bm3);
    if(bm2<k) gx2 = dfs(c+1,s+a[c][2],bm1,bm2+1,bm3);
    if(bm3<k) gx3 = dfs(c+1,s+a[c][3],bm1,bm2,bm3+1);
    return max(max(gx1,gx2),gx3);
}
bool pd(ll l,ll r){
    return l>r;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n>200){
            ll ss[n+1];
            for(ll i=1;i<=n;i++){
                cin>>ss[i];
                ll sss,ssss;
                cin>>sss>>ssss;
            }
            sort(ss+1,ss+n+1,pd);
            ll s=0;
            for(ll i=1;i<=n/2;i++){
                s += ss[i];
            }
            cout<<s<<endl;
            continue;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<4;j++){
                cin>>a[i][j];
            }
        }
        cout<<dfs(1,0,0,0,0)<<endl;
    }
    return 0;
}
