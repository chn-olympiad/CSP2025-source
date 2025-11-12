#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
pair<string,string> a[N];
ll n,q;

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    while(q--){
        string stra,strb;
        cin>>stra>>strb;
        ll len=stra.size(),ans=0;
        for(ll i=0;i<len;i++){
            if(stra.substr(0,i+1)!=strb.substr(0,i+1)){
                break;
            }
            for(ll j=1;j<=n;j++){
                if(i+a[j].first.size()>=len) break;
                if(stra.substr(i+1,a[j].first.size())==a[j].first && strb.substr(i+1,a[j].second.size())==a[j].second
                && stra.substr(i+a[j].first.size()+1,len-i-a[j].first.size()-1)==strb.substr(i+a[j].second.size()+1,len-i-a[j].second.size()-1)){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
