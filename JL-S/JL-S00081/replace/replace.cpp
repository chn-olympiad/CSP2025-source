#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<string>strs;
    unordered_map<string,string>mp;
    unordered_set<string>st;
    for(int i=1;i<=n;++i){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1]=s2;
        st.insert(s1);
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        int l,r;
        for(int i=0;i<s1.size();++i){
            if(s1[i]!=s2[i]){
                l=i;
                break;
            }
        }
        for(int i=s1.size()-1;i>=0;--i){
            if(s1[i]!=s2[i]){
                r=i;
                break;
            }
        }
        int ans=0;
        for(int i=0;i<s1.size();++i){
            string k1="",k2="";
            for(int j=i;j<s1.size();++j){
                k1+=s1[j];
                k2+=s2[j];
                if(st.find(k1)!=st.end()){
                    if(mp[k1]==k2&&i<=l&&j>=r)++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
