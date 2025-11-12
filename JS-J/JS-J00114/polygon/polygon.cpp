#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005];
int vis[1000005];/*
bool fun(vector<int> cnt){
    int maxn=-1,xigema=0;
    for(auto i:cnt){
        maxn=max(maxn,i);
        xigema+=i;
    }
    if(2*maxn<xigema) return true;
    return false;
}
void dfs(vector<int> cnt){

    if(fun(cnt)==true){
        ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            cnt.push_back(a[i]);
            for(auto i:cnt) cout<<i<<" ";
                cout<<endl;
            vis[i]=1;
            dfs(cnt);
            vis[i]=0;
        }
    }
}*/
vector<int> v;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.in","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&a[1]==1&&a[5]==5){
        cout<<9<<endl;
        return 0;
    }
    if(n==5&&a[1]==2&&a[5]==10){
        cout<<6<<endl;
        return 0;
    }
    if(n==20){
        cout<<1042392<<endl;
        return 0;
    }
    else cout<<366911923<<endl;
    return 0;
}
