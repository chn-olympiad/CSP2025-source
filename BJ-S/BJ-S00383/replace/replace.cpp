#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q;
using PSS=pair<string,string>;
PSS s[N];
int solve(string sa,string sb){
    if(sa.size()!=sb.size()) return 0;
    int ans=0;
    for(int i=1;i<=n;i++){
        string pattern=s[i].first;
        int pt=0;
        while(pt<=sa.size()&&pt!=0xffffffffffffffff){
            pt=sa.find(pattern,pt);
            if(pt!=0xffffffffffffffff){
                string tmp=sa.substr(0,pt)+s[i].second+sa.substr(pt+s[i].first.size(),sa.size());
                //cout<<pt<<':'<<tmp<<"####";
                if(tmp==sb)
                    ans++;
                pt+=s[i].first.size();
            }

        }
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].first>>s[i].second;
    }
    for(int i=1;i<=q;i++){
        string sa,sb;
        cin>>sa>>sb;
        cout<<solve(sa,sb)<<'\n';
    }
    return 0;
}
