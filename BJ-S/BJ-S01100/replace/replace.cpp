#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N],cs[N],a,b;
bool foun(int k,int j){
    if(a.size()-j+1<s[k].size()) return false;
    for(int i=0;i<s[k].size();i++){
        if(a[j+i]!=s[k][i]) return false;
    }
    for(int i=0;i<cs[k].size();i++){
        if(b[j+i]!=cs[k][i]) return false;
    }
    for(int i=0;i<j;i++){
        if(a[i]!=b[i]) return false;
    }
    for(int i=j+s[k].size();i<a.size();i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}
bool fin(int k){
    for(int i=0;i<a.size();i++){
        if(a[i]==s[k][0]){
            if(foun(k,i)==true) return true;
        }
    }
    return false;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>cs[i];
    }
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        for(int j=1;j<=n;j++){
            if(fin(j)==true){
                ans++;
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
}
