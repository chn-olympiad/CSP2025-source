#include<bits/stdc++.h>;
using namespace std;
int cnt=0;
int a[5005];
bool vis[5005];
int n;
void dfs(int num,int he,int maxn){
    if(num>n){
        he=0;
        return;
    }else if(num>=3&&maxn*2<he){
        cnt++;
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]==0){
            vis[a[i]]=1;
            maxn=max(a[i],maxn);
            dfs(num+1,he+a[i],maxn);
        }
    }
    return;
}
int  main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    sizeof(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3){
        int maxx=0;
        maxx=max(a[1],a[2]);
        maxx=max(maxx,a[3]);
        if(a[1]+a[2]+a[3]>maxx*2){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    dfs(0,0,0);
    cout<<cnt%998244353*6;
    return 0;
}
