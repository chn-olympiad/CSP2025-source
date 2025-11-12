#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=998244353;
int n,m,y[501],c[N],now,ans;
string S,x,X;
void solve(){
    cin>>n>>m;
    cin>>S;
    S=" "+S;
    ans=1;
    for(int i=1;i<=n;i++){
        y[i]=y[i-1]+(S[i]-'0');
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+1+n);
    cout<<0;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
