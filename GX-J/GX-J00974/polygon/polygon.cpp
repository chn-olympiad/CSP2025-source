#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
bool vis[5005];
int a[5005];
int n,ans,rp;
int pas[5005];
void dfs(int pos,int maxn,int sum){
    if(pos>n+1) return ;
    if(pos>=3 and sum>2*maxn){
        //for(int i=1;i<pos;i++) cout<<pas[i]<<" ";
        //cout<<endl;
        ans++;
        ans%=mod;
    }
    for(int i=pas[pos-1];i<=n;i++){
        if(vis[i])continue;
        pas[pos]=i;
        vis[i]=true;
        dfs(pos+1,max(maxn,a[i]),sum+a[i]);
        vis[i]=false;
    }
}
int main(){
	rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;rp++;
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    pas[0]=1;
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
