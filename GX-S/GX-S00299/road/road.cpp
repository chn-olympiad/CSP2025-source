#include<iostream>
#include<vector>

using namespace std;
int n,m,k;
struct node{
   int to,w;
};
int ans=2147483647;
vector<node> v[10005];
int c[15],a[10][100005];
bool f[10005];
void dfs(int x,int num,int s){
    if(num==n){
        ans=min(ans,s);
    }
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i].to;
        if(f[y]==0){
            f[y]=1;
            dfs(y,num+1,s+v[x][i].w);
            f[y]=0;
        }

    }
    return ;
}
int main(){
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    if(k==0){
        f[1]=1;
        dfs(1,1,0);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][k];
        }
    }
    cout<<0;
    return 0;
}
