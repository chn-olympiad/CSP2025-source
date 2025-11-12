#include <bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
map<string,string> mp;
long long check(string in,string out,string s1,string s2){
    auto it=in.find(s1);
    long long ans=0;
    int len1=s1.size(),lenin=in.size(),lenout=out.size(),len2=s2.size();
    string s;
    while(it!=string::npos){
        s=out.substr(it,len1);
        if(s==s2){
            ans++;
            
        }
        if((it+len1)<lenin){
            in="";
        }
        else
            in=in.substr(it+len1);
    }
    return ans;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        string x,y;
        cin>>x>>y;
        mp[x]=y;
    }
    cout<<0;
    // while(q--){
    //     string in,out;
    //     cin>>in>>out;
    //     for(auto it:mp){
    //         ans+=check(in,out,it.first,it.second);
    //     }
    //     cout<<ans<<endl;
    // }
    return 0;
}   