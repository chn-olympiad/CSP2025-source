#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m,k,ans;
int g[11005][11005];
bool bj[11005];
int dis[11005];
int c[15],w[15][11005];
void Prim_tree(int st){
    memset(dis,0x3f,sizeof(dis));
    memset(bj,0,sizeof(bj));
    dis[st]=0;
    while(true){
        /*
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<' ';
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<bj[i]<<' ';
        }
        cout<<endl;
        cout<<"ANS:"<<ans;
        cout<<endl;
        */
        int u=-1;
        for(int i=1;i<=n;i++){
            if(!bj[i]&&(u==-1||dis[i]<dis[u])){
                u=i;
            }
        }
        if(u==-1) break;
        bj[u]=true;
        ans+=dis[u];
        for(int i=1;i<=n;i++){
            if(!bj[i]){
                dis[i]=min(dis[i],g[u][i]);
            }
        }
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(g,0x3f,sizeof(g));
    cin>>n>>m>>k;
    if(k==0){
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u][v]=g[v][u]=w;
        }
        Prim_tree(1);
        cout<<ans<<endl;
        return 0;
    }else{
        bool A1=1,A2=0;
        for(int i=1;i<=m;i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u][v]=g[v][u]=w;
        }
        for(int i=1;i<=k;i++){
            int u=i+n;
            cin>>c[i];
            if(c[i]!=0) A1=0;
            for(int v=1;v<=n;v++){
                cin>>w[i][v];
                if(w[i][v]==0) A2=1;
            }
        }
        if(A1&&A2){
            //cout<<"A\n";
            for(int i=1;i<=k;i++){
                int u=i+n;
                for(int v=1;v<=n;v++){
                    g[u][v]=g[v][u]=w[i][v];
                }
            }
            n+=k;
            Prim_tree(1);
            cout<<ans<<endl;
            return 0;
        }else{
            for(int i=1;i<=k;i++){
                int u=i+n;
                for(int v=1;v<=n;v++){
                    g[u][v]=w[i][v];
                    g[v][u]=w[i][v]+c[i];
                }
            }
            n+=k;
            /*
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    printf("%11d ",g[i][j]);
                }
                cout<<endl;
            }
            */
            Prim_tree(1);
            cout<<ans<<endl;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        int u=i+n;
        int c,w;
        cin>>c;
        for(int v=1;v<=n;v++){
            cin>>w;
            g[u][v]=w;
            g[v][u]=w+c;
        }
    }
    n+=k;
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%11d ",g[i][j]);
        }
        cout<<endl;
    }
    */
    Prim_tree(1);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
