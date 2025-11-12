#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q;
struct Node{
    string s1;
    string s2;
};
map<char,vector<Node> > dict;
string x1,x2;
ll ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        string _s1,_s2;
        cin>>_s1>>_s2;
        Node _s;
        _s.s1=_s1;
        _s.s2=_s2;
        dict[_s1[0]].push_back(_s);
    }
    while(q--){
        cin>>x1>>x2;
        if(x1.size()!=x2.size()){
            cout<<0<<endl;
            continue;
        }
        ll ans=0;
        for(ll i=0;i<x1.size();i++){
            for(ll j=0;j<dict[x1[i]].size();j++){
                if(i+dict[x1[i]][j].s1.size()>x1.size() || dict[x1[i]][j][0]!=x2[i]) continue;
                string _s=x1.substr(i,dict[x1[i]][j].s1.size());
                if(_s==dict[x1[i]][j].s1){
                    string _x1=x1;
                    _x1.replace(i,dict[x1[i]][j].s1.size(),dict[x1[i]][j].s2);
                    if(_x1==x2) ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
