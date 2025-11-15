#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n;
ll ans, ma, f1, f2;
vector<ll> a0, a1, a2;
void go2(ll p, ll cur, ll sum, ll c0, ll c1){
    //cout<<p<<" "<<cur<<" "<<sum+cur<<" "<<c0<<" "<<c1<<endl;
    if(p==n-1){
        ma=max(ma, sum+cur);
        return;
    }
    if(c0+1<=n/2) go2(p+1, a0[p+1], sum+cur, c0+1, c1);
    if(c1+1<=n/2) go2(p+1, a1[p+1], sum+cur, c0, c1+1);
    return;
}
void go(ll p, ll cur, ll sum, ll c0, ll c1, ll c2){
    //cout<<p<<" "<<cur<<" "<<sum+cur<<" "<<c0<<" "<<c1<<" "<<c2<<endl;
    if(p==n-1){
        ma=max(ma, sum+cur);
        return;
    }
    if(c0+1<=n/2) go(p+1, a0[p+1], sum+cur, c0+1, c1, c2);
    if(c1+1<=n/2) go(p+1, a1[p+1], sum+cur, c0, c1+1, c2);
    if(c2+1<=n/2) go(p+1, a2[p+1], sum+cur, c0, c1, c2+1);
    return;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ll a[n][3]={};
        a0.resize(n), a1.resize(n), a2.resize(n);
        ans=0, ma=-1, f1=1, f2=1;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<3; j++){
                cin>>a[i][j];
                a0[i]=a[i][0], a1[i]=a[i][1], a2[i]=a[i][2];
                if(j==1&&a[i][j]!=0) f1=0;
                if(j==2&&a[i][j]!=0) f2=0;
            }
        }
        if(n==2){
            for(ll i=0; i<3; i++){
                for(ll j=0; j<3; j++){
                    if(i==j) continue;
                    ma=max(a[0][i]+a[1][j], ma);
                }
            }
            cout<<ma<<endl;
        }else if(f1&&f2){
            sort(a0.begin(), a0.end());
            for(ll i=n-1; i>=n/2; i--) ans+=a0[i];
            cout<<ans<<endl;
        }else if(f2){
            go2(0, a0[0], 0, 1, 0);
            go2(0, a1[0], 0, 0, 1);
            cout<<ma<<endl;
        }else{
            go(0, a0[0], 0, 1, 0, 0);
            go(0, a1[0], 0, 0, 1, 0);
            go(0, a2[0], 0, 0, 0, 1);
            cout<<ma<<endl;
        }
    }
    return 0;
}
