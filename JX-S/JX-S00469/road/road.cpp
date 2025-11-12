#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
int c[15];
int a[10005][10005]={};
int s=0;
int w[1000005];
void dfs(int x){
    bool p=true;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i][j]<=0){
                p=false;
                break;
            }
        }
        if(!p){
            break;
        }
    }
    if(p){
        return;
    }
    if(a[x][x+1]!=0){
        s+=a[x][x+1];
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>w[i];
        a[u][v]=w[i];
        a[v][u]=w[i];
    }
    if(k<=0){
        dfs(1);
        cout<<s;
        return 0;
    }else{
        for(int i=1;i<=k;i++){
            cin>>c[i];
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        sort(w+1,w+m+1,cmp);
        int sum=0;
        for(int i=1;i<=k;i++){
            sum+=w[i];
        }
        cout<<sum;
        return 0;
    }
}
