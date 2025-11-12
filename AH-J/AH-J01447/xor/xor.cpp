#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll vis[10005];
string x10_x2(ll x){
    string s;
    while(x){
        ll r=x%2;
        x/=2;
        s="0"+s;
        s[0]=r+'0';
    }
    return s;
}
ll x2_x10(string x){
    ll quan=1;
    ll sum=0;
    for(int i=x.size()-1;i>=0;i--){
        sum+=(x[i]-'0')*quan;
        quan*=2;
    }
    return sum;
}
ll xors(ll x,ll y){
    string xs=x10_x2(x);
    string ys=x10_x2(y);
    string xy_xor;
    while(xs.size()<32) xs="0"+xs;
    while(ys.size()<32) ys="0"+ys;
    for(int i=0;i<32;i++){
        if(xs[i]==ys[i]) xy_xor=xy_xor+"0";
        else xy_xor=xy_xor+"1";
    }
    return x2_x10(xy_xor);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ll n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            ll xom=0;
            for(int i=l;i<=r;i++){
                xom=xors(xom,a[i]);
            }
            if(xom==k){
                cnt++;
                l=r;
            }
        }
    }
    cout<<cnt;
    return 0;
}
