#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;
};
struct bian{
    int v,w,money;
};
int n,m,k;
vector<node> ve;
int f[1010],ans=0;
int find(int x){
    if(x==x)return x;
    return f[x]=find(x);
}
int _merge(int x,int y){
    f[find(x)]=f[find(y)];
}
bool csp(node x,node y){
    return x.w<y.w;
}
void pf(){
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ve.push_back({u,v,w});
    }
    sort(ve.begin(),ve.end(),csp);
    for(int i=1;i<=m;i++){
        if(find(ve[i].u)!=find(ve[i].v)){
            ans+=ve[i].w;
            _merge(ve[i].u,ve[i].v);
        }
    }
    cout<<ans;
    return;

}
int dp[1010][1010];
int jihuo[25];//你看，连接这个点的次数越多，每次花费的钱就越少！
int uu[1010];//
int mm[25][1010],ans=0;
void fp(){

    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(k==0)pf();
    else fp();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
