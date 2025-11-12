#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    map<string,string>mp;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(q--){
        int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        for(auto it:mp){
            string goal=it.first;
            string t=t1;
            if(t.find(goal)!=18446744073709551615){
                t.replace(t.find(goal),goal.size(),it.second);
                if(t==t2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}