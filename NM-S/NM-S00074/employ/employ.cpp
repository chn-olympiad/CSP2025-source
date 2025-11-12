#include<bits/stdc++.h>
using namespace std;
int n,m;
string diff;
vector<string> smp;
int mp[218];
int vis[218];
void getsmp(int index,string cur){
    if(index == diff.size()){
        smp.push_back(cur);
        return;
    }
    for(int i = 1;i<=n;++i){
        if(vis[i])continue;
        vis[i] = 1;
        getsmp(index+1,cur+char('0'+i));
        vis[i] = 0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>diff;
    for(int i = 1;i<=n;++i){
        cin>>mp[i];
    }
    memset(vis,0,sizeof(vis));
    getsmp(0,"");
    int ans = 0;
    for(string s:smp){
            int d = 0,a = 0;
        for(int i = 0;i<n;++i){
            if(diff[i] == '0')d++;
            if(mp[s[i]-'0']<d)a++;
        }
        if(a>=m)ans++;
    }
    cout<<ans;
}
