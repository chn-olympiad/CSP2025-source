#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200200],c[200200];
long long ans=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>c[i];
    }
    while(q--){
        ans=0;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=1;i<=n;i++){
            int x=0,f=0;
            if((x=s1.find(s[i]))<s1.size()){
                for(int j=0;j<c[i].size();j++){
                    if(s2[x+j]!=c[i][j]){
                        f=1;
                        break;
                    }
                }
                for(int j=0;j<s1.size();j++){
                    if(x<=j&&j<x+c[i].size()){
                        continue;
                    }
                    if(s1[j]!=s2[j]){
                        f=1;
                        break;
                    }
                }
                if(!f){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
