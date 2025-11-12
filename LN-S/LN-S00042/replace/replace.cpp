#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans;
string t1,t2;
unordered_multimap<string,string> um;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++)cin >> t1 >> t2,um.insert({t1,t2});
    while(q--){
        cin >> t1 >> t2;
        int ans=0;
        if(t1.size()!=t2.size()){
            cout << "0\n";
            continue;
        }
        for(auto&p:um){
            for(int k=0,pt=t1.find(p.first,k);~pt;k=pt+1,pt=t1.find(p.first,k)){
                int x=pt+p.first.size();
                if(t1.substr(0,pt)+p.second+t1.substr(x,t1.size()-x)==t2){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
