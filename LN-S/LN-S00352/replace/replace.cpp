#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    string s[200001][2];
    for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
    map<string,string> mp;
    for(int i=1;i<=n;i++) mp[s[i][0]]=s[i][1];
    string t1,t2;
    while(q--){
        cin>>t1>>t2;
        if(mp[t1]==t2) cout<<1<<endl;
    }
    return 0;
}
