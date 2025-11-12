#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long ans;
int a[100010];
bool vis[100010];
bool check(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(vis[i])
            sum+=a[i];
    }
    int Max=INT_MIN;
    for(int i=1;i<=n;i++){
        if(Max<a[i]&&vis[i]){
            Max=a[i];
        }
    }
    if(sum>Max*2) return 1;
    return 0;
}
void dfs(int pos,int k){
    if(pos==k+1){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                sum++;
                //cout<<a[i]<<" ";
            }
        }
        //cout<<endl;
        if(check()&&sum==k){
            ans++;
            ans%=mod;
            //for(int i=1;i<=n;i++){
            //    if(vis[i]){
            //        cout<<a[i]<<" ";
            //    }
            //}
            //cout<<endl;
        }
        return;
    }
    for(int i=pos;i<=n;i++){
        vis[i]=1;
        dfs(pos+1,k);
        vis[i]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=3;i<=n;i++){
        memset(vis,0,sizeof(vis));
        dfs(1,i);
    }
    cout<<ans+1;
    return 0;
}
