#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    map<string,string> mp;
    while(n--){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        if(mp.find(t1)==mp.end()||mp[t1]!=t2)cout<<0<<"\n";
    }
    
    return 0;
}
