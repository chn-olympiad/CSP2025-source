#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}a[114514];
vector<int>g[114514];
bool b[114514];
bool cmp(node x,node y){
    return x.c<y.c;
}
void dfs(int u,int a){
    if(b[u])return;
    b[u]=1;
    for(int i=0;i<g[u].size();i++){
        int son=g[u][i];
        if(son==a)continue;
        dfs(son,u);
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>a[i].a>>a[i].b>>a[i].c;
    sort(a+1,a+1+n,cmp);
    long long ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)b[j]=0;
        g[a[i].a].push_back(a[i].b);
        g[a[i].b].push_back(a[i].a);
        ans+=a[i].c;
        dfs(1,0);
        bool flag=0;
        for(int j=1;j<=n;j++){
            if(b[j]==0){
                flag=1;
                break;
            }
        }
        if(flag==0)break;
    }
    cout<<ans;
    return 0;
}
