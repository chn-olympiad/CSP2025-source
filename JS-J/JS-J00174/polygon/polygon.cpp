#include<bits/stdc++.h>
using namespace std;
int dfs(vector<int> bas,int maxn){
    int res=0,ress=0;
    for(int i=0;i<bas.size();i++) res+=bas[i];
    if(res<=maxn) return 0;
    if(bas.size()==2) return 1;
    for(int i=0;i<bas.size();i++){
        vector<int> based;
        for(int j=0;j<bas.size();j++) if(j!=i) based.push_back(bas[j]);
        ress+=dfs(based,maxn);
    }return ress+1;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n; cin>>n; int a[n];
    long long int ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=2;i<n;i++){
        vector<int> based;
        for(int j=0;j<i;j++) based.push_back(a[j]);
        int re=dfs(based,a[i]);
        ans+=re;
    }cout<<ans;
    return 0;
}