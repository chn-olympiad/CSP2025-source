#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,in,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++){
        cin>>in>>in>>in;
        ans+=in;
    }
    cout<<ans;
    return 0;
}
