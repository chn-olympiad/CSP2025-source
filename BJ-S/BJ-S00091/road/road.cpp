#include<bits/stdc++.h>
using namespace std;
struct r{
    int x,y,z;
};
vector<r>edge[100000100];
int f[10100],ctoc[10010][10010],city[10100];
int Find(int t){
    if(f[t]==t)return t;
    return f[t]=Find(f[t]);
}void Union(int a,int b){
    int ra=Find(a),rb=Find(b);
    f[ra]=rb;
}bool cmp(r a,r b){
    return a.z<b.z;
}
void solve(){
    int n,m,k,id=1,cnt=0;
    long long sum;
    cin>>n>>m>>k;
    memset(ctoc,2e9,sizeof ctoc);
    for(int i=1;i<=n;i++)f[i]=i,ctoc[i][i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ctoc[u][v]=ctoc[v][u]=min(ctoc[u][v],w);
        id++;
    }for(int i=1;i<=k;i++){
        int u,w;
        cin>>u;
        for(int j=1;j<=n;j++){
            cin>>w;
            city[j]=w;
        }for(int j=1;j<=n;j++){
            for(int q=j+1;q<=n;q++){
                ctoc[j][q]=min(ctoc[j][q],city[j]+city[q]+u);
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edge[id].push_back(r{i,j,ctoc[i][j]});
            id++;
        }
    }sort(edge+1,edge+1+id,cmp);
    for(int i=1;i<id;i++){
        int u=edge[i].x,v=edge[i].y,w=edge[i].z;
        if(Find(u)!=Find(v)){
            Union(u,v);
            sum+=w;
            cnt++;
            if(cnt==n)break;
        }
    }cout<<sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
