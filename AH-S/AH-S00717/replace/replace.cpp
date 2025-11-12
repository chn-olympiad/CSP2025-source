#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,q,ans;
string a,b;
struct sg{
    string s1,s2;
}dis[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++) cin>>dis[i].s1>>dis[i].s2;
    while(q--){
        cin>>a>>b;
        ans=0;
        for(ll i=1;i<=n;i++){
            ll l=a.find(dis[i].s1);
            ll r=l+ll(dis[i].s1.size());
            if(l==string::npos) continue;
            bool flag=true;
            if(b.substr(l,dis[i].s1.size())!=dis[i].s2) continue;
            for(ll i=0;i<l;i++)
                if(a[i]!=b[i]){
                    flag=false;
                    break;
                }
            if(!flag) continue;
            for(ll i=r;i<ll(a.size());i++)
                if(a[i]!=b[i]){
                    flag=false;
                    break;
                }
            if(!flag) continue;
            ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
