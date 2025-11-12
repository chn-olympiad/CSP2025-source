#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[100005],t[100005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
    while(q--){
        string x,y;
        cin>>x>>y,ans=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j+s[i].size()-1<x.size();j++)
                if(x.substr(j,s[i].size())==s[i])
                    if(x.substr(0,j)+t[i]+x.substr(j+s[i].size())==y)
                        ans++;
        cout<<ans<<"\n";
    }
}