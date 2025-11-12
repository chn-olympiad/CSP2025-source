#include <bits/stdc++.h>
using namespace std;
int n,q;
string x,y;
unordered_map<string,vector<pair<string,string>>> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){cin>>x>>y; int l=0,r=x.size()-1;while(l<x.size()&&x[l]==y[l]) l++; while(l<=r&&x[r]==y[r]) r--; mp[x.substr(l,r-l+1)+'&'+y.substr(l,r-l+1)].push_back({x.substr(0,l),r+1==x.size()?"":x.substr(r+1,x.size()-r-1)});}//cout<<x.substr(l,r-l+1)+'&'+y.substr(l,r-l+1)<<' '<<x.substr(0,l)<<' '<<(r+1==x.size()?"":x.substr(r+1,x.size()-r-1))<<'\n';}
    while(q--){
        cin>>x>>y;int l=0,r=x.size()-1;while(l<x.size()&&x[l]==y[l]) l++; while(l<=r&&x[r]==y[r]) r--;
        int ans=0;
        for(auto p:mp[x.substr(l,r-l+1)+'&'+y.substr(l,r-l+1)]) if(l-p.first.size()>=0&&r+p.second.size()<x.size()&&p.first==x.substr(l-p.first.size(),p.first.size())&&p.second==(r+1==x.size()?"":x.substr(r+1,p.second.size()))) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
