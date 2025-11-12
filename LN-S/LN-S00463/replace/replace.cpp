#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int bid1[200005],bid2[200005],siz[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        for(int j=0;j<t.size();j++){
            if(t[j]=='b'){
                bid1[i]=j;
                break;
            }
        }
        cin>>t;
        for(int j=0;j<t.size();j++){
            if(t[j]=='b'){
                bid2[i]=j;
                break;
            }
        }
        siz[i]=t.size();
    }
    for(int i=1;i<=m;i++){
        string t1,t2;
        cin>>t1>>t2;
        int bidt1;
        int bidt2;
        if(t1.size()!=t2.size()){
            cout<<0;
            continue;
        }
        for(int j=0;j<t1.size();j++){
            if(t1[j]=='b') bidt1=j;
        }
        for(int j=0;j<t2.size();j++){
            if(t2[j]=='b') bidt2=j;
        }
        for(int i=1;i<=n;i++){
            if(t1.size()<siz[i]) continue;
            if(bidt1-(bid1[i]-bid2[i])==bidt2) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
