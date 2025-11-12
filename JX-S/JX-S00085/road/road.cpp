#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    int w;
}a[100000];
const int N=10005;
vector<node> e[N];
int vi[15][N];
int mp[10015][10015];
int n,m,k,x,y,z,vis[N],d[N],aa;
long long ans;
bool cmp(node a1,node a2){
    return a1.v>a2.v;
}
void road(){//
    //queue<pair<int,int> > q;
    //q.push(1,9);
    for(int i=0;i<=n;i++)d[i]=INT_MAX;

    a[aa].v=0;
    a[aa].w=1;
    aa++;
    d[1]=0;

    while(aa){

        sort(a,a+aa,cmp);

        int u=a[--aa].w;

        if(vis[u])continue;

        //if(u<=n)
            vis[u]=1;

        ans+=d[u];
        //cout<<"2q";
        for(int i=1;i<=n;i++){
            if(mp[u][i]==-1)continue;
            if(d[i]>mp[u][i]){
                d[i]=mp[u][i];
                a[aa].v=d[i];
                a[aa].w=i;
                aa++;
                //cout<<d[i]<<i<<endl;
            }
        }
        /*for(int i=n+1;i<=n+k;i++){
            if(mp[u][i]==-1)continue;
            if(d[i]+vis2>mp[u][i]){
                d[i]=mp[u][i];
                a[aa].v=d[i];
                a[aa].w=i;
                aa++;
                //cout<<d[i]<<i<<endl;
            }
        }*/
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<=n+k+1;i++){
        for(int j=0;j<=n+k;j++){
            mp[i][j]=-1;
        }
    }

    for(int i=0;i<m;i++){
        cin>>x>>y>>z;
        mp[x][y]=z;
        mp[y][x]=z;
    }
    /*for(int i=1;i<=k;i++){
        cin>>vis2[i];
        for(int j=1;j<=n;j++){
            cin>>mp[n+i][j];
            mp[j][n+i]=mp[n+i][j];
        }
    }*/
    road();
    cout<<ans;
    return 0;
}

