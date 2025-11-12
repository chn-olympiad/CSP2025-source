#include<bits/stdc++.h>
using namespace std;

int n,maxn,ans;
const int MAXN=5000+10;
int a[MAXN];
bool vis[MAXN];
void dfs(int dep,int sum,int maxn){
    if(sum>maxn*2){
        ans++;
        ans%=998244353;
    }
    if(dep>=n)return;
    else for(int i=dep;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(dep+1,sum+a[i],max(maxn,a[i]));
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<ans<<endl;
    return 0;
}
