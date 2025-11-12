#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+17;
struct node{
    int u;
    int v;
    int w;
};
int g[20][MAXN],c[20];
int father[MAXN];
int n,m,k;
long long ans;
vector <node> e;
node o;
bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int x){
    if(x==father[x]){
        return x;
    }
    return father[x]=find(father[x]);
}
void unionn(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        father[x]=y;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++){
        father[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        //g[x][y]=g[y][x]=z;
        o.u=x;
        o.v=y;
        o.w=z;
        e.push_back(o);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
        }
    }
    if(k==0){
        sort(e.begin(),e.end(),cmp);
        int cnt=0;
        for(auto i:e){
            if(cnt==n-1){
                break;
            }
            if(find(i.u)!=find(i.v)){
                unionn(i.u,i.v);
                //cout<<i.u<<" "<<i.v<<endl;
                ans+=i.w;
                cnt++;
            }
        }
        cout<<ans;
        return 0;
    }

    return 0;
}
