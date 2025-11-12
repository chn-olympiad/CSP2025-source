#include <bits/stdc++.h>
using namespace std;

int n,q,ans;
int qiandao[200005][3];
int houdao[200005][3];
void dfs(int x,int sum,int len){
    if(sum==qiandao[0][2]){
        ans++;
        return;
    }
    for(int i=x+1;i<=n;i++){
        if(qiandao[i][1]<=sum && houdao[i][1]<=len-sum-1){
            dfs(i,sum+(qiandao[i][2]-qiandao[i][1]),len);
        }
    }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                qiandao[i][1]=j;
                houdao[i][1]=s1.size()-j-1;
            }
            if(s2[j]=='b'){
                qiandao[i][2]=j;
                houdao[i][2]=s2.size()-j-1;
            }
        }
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                qiandao[0][1]=j;
                houdao[0][1]=s1.size()-j-1;
            }
            if(s2[j]=='b'){
                qiandao[0][2]=j;
                houdao[0][2]=s2.size()-j-1;
            }
        }
        dfs(0,qiandao[0][1],s1.size());
    }
    cout<<ans;
    return 0;
}