#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
#include<stdio.h>
unordered_map<string,string> mp;
string s1,s2;
size_t sz1,sz2,ans;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(q--){
        ans=0;
        cin>>s1>>s2;
        sz1=s1.length();sz2=s2.length();
        if(sz1!=sz2){
            cout<<"0\n";
            continue;
        }
        for(int i=0;i<sz1-1;i++){
            for(int j=1;j<sz2;j++){
                if(mp[s1.substr(i,j)]==s2.substr(i,j))ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}