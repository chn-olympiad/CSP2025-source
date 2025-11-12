#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[20],v[20],fa[10010],ans;
struct D{
    int v,w;
};
vector<D>e[10010];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int f(int x){
    if(fa[x]==x)return x;
    int y=f(fa[x]);
    fa[x]=y;
    return y;
}
void mm(int x,int y){
    fa[f(x)]=f(y);
}
bool C(){
    for(int i=2;i<=n;i++){
        if(f(fa[i])!=f(fa[i-1])){
            return false;
        }
    }
    return true;
}
int Dij(int x){
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=0;i<e[1].size();i++){
        int z=e[1][i].v;
        //cout<<1<<' '<<z<<' '<<e[1][i].w<<'\n';
        if(f(1)!=f(z)){
                //cout<<1<<' '<<z;cout<<'\n';
                //for(int i=1;i<=n+k;i++)cout<<f(fa[i])<<' ';
                //cout<<'\n';
            //mm(1,z);
            q.push(make_pair(e[1][i].w,z));
        }
    }
    int xx=x,xxx;
    while(q.size()){
        int y=q.top().second,yy=q.top().first;
        mm(xx,y);
        xx=y;
        //cout<<yy<<' '<<y<<'\n';
        //for(int i=1;i<=n+k;i++)cout<<f(fa[i])<<' ';
        //cout<<'\n';
        ans+=yy;
        if(yy==xxx)ans-=yy;
        xxx=yy;
        q.pop();
        if(C())break;
        for(int i=0;i<e[y].size();i++){
            int z=e[y][i].v;
            //cout<<y<<' '<<z<<' '<<e[y][i].w<<'\n';
            if(f(y)!=f(z)){
                    //cout<<y<<' '<<z;cout<<'\n';
                //for(int i=1;i<=n+k;i++)cout<<f(fa[i])<<' ';
                //cout<<'\n';
                //mm(y,z);
                q.push(make_pair(e[y][i].w,z));
            }if(y>n && !v[y]){
                ans+=c[y-n];
                v[y]=1;
            }
        }

    }
}
signed main(){
    freopen("road1.in","r",stdin);
    freopen("road1.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        e[u].push_back((D){v,w});
        e[v].push_back((D){u,w});
    }
    for(int i=1,cc;i<=k;i++){
        cin>>c[i];
        if(c[i]%2){
            cc=c[i]/2;
            c[i]=0;
        }else{
            cc=(c[i]-1)/2;
            c[i]=1;
        }
        for(int j=1,w;j<=n;j++){
            cin>>w;
            e[j].push_back((D){n+i,w+cc});
            e[n+i].push_back((D){j,w+cc});
        }
    }
    Dij(1);
    int x=f(fa[1]);
    //cout<<x;
    for(int i=n+1;i<=n+k;i++){
        if(f(fa[i])==x){
                //cout<<f(fa[i]);
            ans+=c[i];
        }
    }
    cout<<ans;
    return 0;
}
