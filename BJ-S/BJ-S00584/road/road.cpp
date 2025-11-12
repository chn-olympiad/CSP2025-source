#include<bits/stdc++.h>
using namespace std;
struct node{
    int v,w;
};
struct node1{
    int u,v,w;
};
int n,m,k,fa[10010],cnt;
long long ans=0;
vector<node> vt[10010];
node1 s[10010];
bool cmp(node1 x,node1 y){
    return x.w<y.w;
}
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    fa[get(x)]=fa[get(y)];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>s[i].u>>s[i].v>>s[i].w;
        //vt[u].push_back({v,w});
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(s+1,s+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=s[i].u,v=s[i].v,w=s[i].w;
        //for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
        if(get(u)==get(v))continue;
        merge(u,v);
        ans+=w;
        cnt++;
        //cout<<s[i].u<<" "<<s[i].v<<endl;
    }
    //for(int i=1;i<=n;i++)cout<<fa[i]<<" ";
    cout<<ans;

    return 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
