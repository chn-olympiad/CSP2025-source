#include<bits/stdc++.h>
using namespace std;
string s1[1005],s2[1005],t1[1005],t2[1005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
    for(int t=1;t<=q;t++){
        cin>>t1[t]>>t2[t];
        int ans=0;
        for(int i=1;i<=n;i++){
            int kmp=0;
            for(int j=0;j+s1[i].size()-1<t1[t].size();j++){
            int kmp2=1;
                 for(int k=0;k<j;k++){
                    if(t1[t][k]!=t2[t][k]){
                        kmp2=0;break;
                    }
                 }
                 //cout<<kmp2;
                 for(int k=0;k<s1[i].size();k++){
                    if(s1[i][k]==t1[t][j+k]&&s2[i][k]==t2[t][j+k])continue;
                    kmp2=0;break;
                 }
                 //cout<<kmp2;
                 for(int k=j+s1[i].size();k<t1[t].size();k++){
                    if(t1[t][k]!=t2[t][k]){
                        kmp2=0;break;
                    }
                 }
                 //cout<<kmp2;
                 if(kmp2){
                    kmp=1;break;
                 }
            }
            ans+=kmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
