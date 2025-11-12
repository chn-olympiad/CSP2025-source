#include<bits/stdc++.h>
using namespace std;
int s[25];
int n,ans=0;
void dfs(vector<int> &used,int idx,int total,int MAX){
    if(idx>=n) return;
    dfs(used,idx+1,total,MAX);
    used.push_back(s[idx]);
    total+=used[used.size()-1];
    MAX=max(MAX,used[used.size()-1]);
    if(used.size()>=3&&total>MAX*2) ans++;
    dfs(used,idx+1,total,MAX);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    vector<int> used;
    dfs(used,0,0,0);
    cout<<(ans%998244353);
    return 0;
}
