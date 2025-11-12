#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string h_or_e;
int a[10005],n,m,ans;
bool vis[10005]={};
void dfs(vector<int>num,int x){
    if(x>=n){
        int loser=0,aaa=0;
        int k=0;
        for(k;k<n;k++)
        if(h_or_e[k]=='0'){
            loser++;
        }else if(loser>=num[k]){
            loser++;
        }else{
            aaa++;
        }
        if(aaa>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            num.push_back(a[i]);
            dfs(num,x+1);
            num.pop_back();
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>h_or_e;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>AK;
    dfs(AK,0);
    cout<<ans;
    return 0;
}