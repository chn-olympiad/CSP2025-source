#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fr(xx,aa,bb) for(xx=aa;xx<=bb;xx++)
#define rf(xx,aa,bb) for(xx=aa;xx>=bb;xx--)
const ll N=1e5;
const ll inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;

int n,a[N];
ll ans;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll i,j,k,l,m;

    cin>>n;
    fr(i,1,n)cin>>a[i];
    fr(i,1,n){
        ll x=1;
        fr(j,1,i)x=x*(n-j)%mod;
        ans=(ans+x)%mod;
    }
    cout<<ans;
    
    // fprintf(stderr,"used time = %ldms\n",1000*clock()/CLOCKS_PER_SEC);
    return 0;
}
/*

*/
//g++ polygon.cpp -o polygon -O2 -std=c++14 -static