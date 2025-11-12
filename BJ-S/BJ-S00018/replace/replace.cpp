#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010],t[200010],w,z;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        int ans=0;
        cin>>w>>z;
        if(w.size()!=z.size()){
            cout<<0<<endl;
            continue;
        }
        int m=w.size();
        w=" "+w;
        z=" "+z;
        for(int i=1;i<=m;i++){
            for(int j=i+1;j<=m;j++){
                if(i!=1){
                    if(w.substr(1,i-1)!=z.substr(1,i-1)){
                        continue;
                    }
                }
                if(j!=m){
                    if(w.substr(j+1)!=z.substr(j+1)){
                        continue;
                    }
                }
                for(int k=1;k<=n;k++){
                    if(w.substr(i,j-i+1)==s[k] && t[k]==z.substr(i,j-i+1)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
