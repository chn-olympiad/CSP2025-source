#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string s[100005][2];
    bool fei[100005]={0};
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(int i=1;i<=n;i++){
            int o=0;
            for(int j=0;j+s[i][0].size()-1<t1.size();j++){
                if(t1.substr(j,s[i][0].size())==s[i][0]&&t1.substr(0,j)+s[i][1]+t1.substr(j+s[i][0].size(),t1.size()-j-s[i][0].size())==t2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
