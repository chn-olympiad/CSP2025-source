#include<bits/stdc++.h>
using namespace std;
int n,a[5001],cnt=0,vis[5001]={};
void dfs(int x,int sum,int maxn,int j){
    if(vis[j]==0)sum+=a[j];
    if(a[j]>maxn)maxn=a[j];
    vis[j]=1;
    if(x==3||x==4){
        if(sum>maxn*2){
            cnt++;
            return;
        }
        if(x==4)return;
    }
    dfs(x+1,sum,maxn,j+1);
    vis[j]=0;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5001];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(3,0,0,1);
    cout<<cnt%998244353;
    return 0;
}
