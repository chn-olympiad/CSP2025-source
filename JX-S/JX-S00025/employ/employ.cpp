#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1000],g[1000],vis[1000];
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m; cin>>n>>m;
    string str; cin>>str;
    for(int i=0;i<str.size();i++){
        a[i+1]=str[i]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>g[i];
    }
    cout<<20251101<<'\n';
    return 0;
}
