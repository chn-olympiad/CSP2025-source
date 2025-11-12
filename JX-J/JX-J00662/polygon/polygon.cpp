#include<bits/stdc++.h>
using namespace std;
int n,a[5005],v[5005]={0},ans=0;
int vis[5005]={0};
void dfs(int x,int c,int la){
    if(c==x+1){
        long long s=0;
        int m=0;
        for(int i=1;i<=c-1;i++){
            s+=v[i];
            m=max(v[i],m);
        }
        if(s>m*2) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&a[i]>la){
            vis[i]=1;
            v[c]=a[i];
            dfs(x,c+1,a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(i,1,0);
    }
    cout<<ans;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
