#include<bits/stdc++.h>;
using namespace std;
int n,m;
long long ans=0;
long long num=1;
int vis[10001];
long long last=0;
int s[10001],a[10001],sss[10001];
void dfs(int step,int guo){
    if(step>n){
        //cout<<guo<<" ";
        if(guo>=m){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(a[i]>sss[step]&&s[step]==1){
                    guo++;
                    step++;
                    dfs(step,guo);
                    step--;
                    vis[i]=0;
                    guo--;
            }
            else{
                step++;
                dfs(step,guo);
                step--;
                vis[i]=0;
            }
        }
    }
}
int main(){
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%1d",&s[i]);
        if(s[i]==0){
            last++;
            sss[i+1]=last;
        }
        //cout<<sss[i]<<" ";
        num*=i;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        cout<<num%998244353;
        return 0;
    }
    dfs(1,0);
    cout<<ans%998244353;
    return 0;
}
