#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
bool vis[5005];
void dfs(int step,int ed,int sum,int cp/*compare*/,int l){
    if(step==ed+1){
        if(sum>cp*2){
            ans++;
            ans%=998244353;
            //cout<<step<<" "<<ed<<" "<<sum<<" "<<cp<<"\n";
            return ;
        }
    }
    for(int i=l;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(step+1,ed,sum+a[i],max(cp,a[i]),i+1);
            vis[i]=0;
        }
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int e=3;e<=n;e++){
        memset(vis,0,sizeof(vis));
        dfs(1,e,0,0,1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
