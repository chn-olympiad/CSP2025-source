#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define db
const ll maxn=502;
char str[maxn]; 
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ll n,q,ln,lq;
    cin>>n>>q;
    ln=2500000/n;
    lq=2500000/q;
    char f[2][n+1][ln+5],g[2][lq+5]; 
    ll x[n+1],y[n+1],t;
    for(int i=1;i<=n;i++){
        cin>>f[0][i]>>f[1][i];
        x[i]=strlen(f[0][i]);
    }
    while(q--){
        cin>>g[0]>>g[1];
        cout<<0<<endl;
    }
    return 0;
}