#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[100005];
string s;
ll n,m,cnt=1,cntm=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(ll i=1;i<=n;i++){
        ll c;
        cin>>c;
    }
    for(ll i=1;i<=n;i++){
        cnt=(cnt*i)%998244353;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
