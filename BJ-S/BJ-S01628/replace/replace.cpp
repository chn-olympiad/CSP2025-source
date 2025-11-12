#include<bits/stdc++.h>
using namespace std;
map<string,string> mp;
string tmp,tmp2;
int ans;
void dfs(string now,string to){
    if(to==now){
        ans++;
        return;
    }
    int len=now.size();
    bool flag=false;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            tmp="";
            for(int k=i;k<j;k++){
                tmp+=now[k];
            }
            for(pair<string,string> p:mp){
                if(tmp==p.first){
                    flag=true;
                    tmp2=now;
                    for(int k=i;k<j;k++){
                        tmp2[k]=p.second[k-i];
                    }
                    dfs(tmp2,to);
                }
            }
        }
    }

    if(!flag)return;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string s1,s2;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(q--){
        cin>>s1>>s2;
        ans=0;
        dfs(s1,s2);
        cout<<ans<<endl;
    }
    return 0;
}
