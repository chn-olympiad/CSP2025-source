#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
int fa[1000005],cnt;//1 ≤ n ≤ 10^4 ,1 ≤ m ≤ 10^6 ,0 ≤ k ≤ 10
int c[15];
struct node{
    long long bg,ed,value;
};
node a[1000005];
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    return ;
}
int find(int idx){
    if(fa[idx]==idx){
        return idx;
    }
    return fa[idx]=find(fa[idx]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        return ;
    }
    fa[x]=y;
}
long long prim(){
    long long sum=0,ps=0;
    init();
    for(int i=1;i<=cnt;i++){

        if(!same(a[i].bg,a[i].ed)){
            unite(a[i].bg,a[i].ed);
            sum+=a[i].value;
            ps++;
            if(ps==n-1){
                return sum;
            }
            cout<<a[i].value<<" ";
        }
    }
    return sum;
}
long long v[15][1000005],w=0,minn=0x3f3f3f3f3f3f3f3f;
int ss;
int vis[15];
bool cmp(node x,node y){
    return x.value<y.value;
}
void dfs(int x){
    if(x==k+1){
        cnt=ss;
        int oo=0;
        for(int i=1;i<=k;i++){
            oo+=c[i]*vis[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    cnt++;
                    int ppp=0;
            a[cnt].value=0x3f3f3f3f3f3f3f3f;
            a[cnt].bg=i;
            a[cnt].ed=j;
                    for(int p=1;p<=k;p++){
                        if(vis[p]){
                            ppp=1;
                            a[cnt].value=min(a[cnt].value,v[p][i]+v[p][j]);
                        }
                    }
                    /*if(ppp==0){
                        cnt--;
                    }*/
            }
        }
        sort(a+1,a+cnt+1,cmp);
        minn=min(prim()+oo,minn);
        return ;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    init();
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        a[++cnt].bg=u;
        a[cnt].ed=v;
        a[cnt].value=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>v[i][j];
        }
        //cout<<c[i]<<" ";
        if(c[i]!=0){
            w=1;
        }
    }
    if(k!=0&&w==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    if(i==j){
                        continue;
                    }
                cnt++;
                a[cnt].value=0x3f3f3f3f3f3f3f3f;
                a[cnt].bg=i;
                a[cnt].ed=j;
                for(int p=1;p<=k;p++){
                    a[cnt].value=min(a[cnt].value,v[p][i]+v[p][j]);
                }
            }
        }
    }
    if(k==0||w==0){
        sort(a+1,a+cnt+1,cmp);
        cout<<prim();
        //cout<<0x3f3f3f3f;
    }else{
        ss=cnt;//cout<<ss<<" ";
        for(int i=1;i<=k;i++){
            cin>>c[i];
            for(int j=1;j<=n;j++){
                cin>>v[i][j];
            }
            if(c[i]!=0){
                w=1;
            }
        }

        dfs(1);
        cout<<minn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
