#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10005],s[10005];
void solve(){
    ll n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1+i;j<=n;j++){
            int y=0;
            for(int k=i;k<=j;k++) y=max(a[k],y);
            if(a[j]-a[i-1]>y) sum++;
        }
    }
    cout<<sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}
