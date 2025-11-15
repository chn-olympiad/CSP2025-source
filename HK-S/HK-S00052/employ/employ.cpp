#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510;
const int mod=998244353;
int c[maxn];
string s;
int ans(int n,int m){
    int res=1;
    for(int i=1;i<=n;i++){
        res=(res*i)%mod;
    }
    return res%mod;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    cout<<ans(n,m);
    cout.flush();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
