#include <bits/stdc++.h>
#define int long long
#define st first
#define nd second
#define MP make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int N=1e3+5,mod=1e9+7;
int quickpow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int n,m,a[N][N],p=-1;
vector<int> v;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    rep(i,0,n*m){
        cin>>a[0][0];
        if(p==-1)p=a[0][0];
        v.push_back(a[0][0]);
    }sort(v.begin(),v.end());
    rep(j,0,m)rep(i,0,n){
        a[i][j]=v.back();
        v.pop_back();
    }
    rep(j,0,m)if(j&1)rep(i,0,n/2)swap(a[i][j],a[n-i-1][j]);
    rep(i,0,n)rep(j,0,m)if(a[i][j]==p)cout<<j+1<<' '<<i+1;
    return 0;
}
