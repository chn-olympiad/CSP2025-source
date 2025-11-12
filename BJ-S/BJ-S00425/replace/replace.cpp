#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
struct xxs{
    string a,b;
}s[1005];
string aa,bb;
bool flag=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
    }
    while(q--){
        cin>>aa>>bb;
        if(aa.size()!=bb.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<aa.size()-s[i].a.size()+1;j++){
                flag=0;
                for(int k=j;k<j+s[i].a.size()+1;k++){
                    if(aa[k]!=s[k-j]){
                        flag=1;
                        break;
                    }
                }
                if(flag) continue;
                for(int k=j;k<j+s[i].a.size()+1;k++){
                    if(bb[k]!=s[k-j]){
                        flag=1;
                        break;
                    }
                }
                if(flag) continue;
                for(int k=0;k<j;k++){
                    if(aa[k]!=bb[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag) continue;
                for(int k=j+s[i].a.size()+2;k<s[i].a.size();k++){
                    if(aa[k]!=bb[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag) continue;
                ans++;
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}